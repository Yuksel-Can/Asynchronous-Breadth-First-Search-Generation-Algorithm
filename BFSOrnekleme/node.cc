#include <string.h>
#include <omnetpp.h>
#include "Packet_m.h"
#define ACK         new cMessage("ack",         1)  //yesil   2-mavi
#define REJECT      new cMessage("reject",      0)  //kirmizi
#define INVALIDATE  new cMessage("invalidate",  4)  //sari -geçersiz kılmak

#define ROOT_NAME "node6"
using namespace omnetpp;

class node : public cSimpleModule{

    int myLayer= -1;
    int parentGate = -1;
    std::vector< cGate* > childs;
    std::vector< cGate* > others;
    std::vector< cGate* > gecici;

    protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(node);

void node::initialize(){
    if(strcmp(getName(),ROOT_NAME) == 0){

        Pack *pk = new Pack("first",2);
        pk->setPACKETTYPE('l');

        scheduleAt(0.0, pk);
    }

}

void node::handleMessage(cMessage *msg){

    cGate *incomedGate = msg-> getArrivalGate(); //baslangicta null döndürür.

    if(strcmp(msg->getName(),"ack") == 0){
        childs.push_back(incomedGate);
        EV <<this->getFullName() << " düğümünün çocukları :";
        for(int i=0; i<childs.size();i++){
            EV << childs.at(i)-> getPreviousGate()-> getOwner()-> getFullName() << " , ";
        }
        EV <<" katman bilgisi : "<< myLayer+1 << "\n";

    }else if(strcmp(msg->getName(),"reject") == 0){
        others.push_back(incomedGate);


    }else if(strcmp(msg->getName(),"invalidate") == 0){

        bubble("Bir çocuk silindi");
        gecici.clear();
        for(int i=0; i<childs.size();i++){

            if(childs[i]->getFullName() != incomedGate->getFullName()){

                gecici.push_back(childs[i]);
            }

        }
        childs.clear();
        EV<<this->getFullName() << " düğümünün yeni çocukları : ";
        for(int i=0; i<gecici.size();i++){

            childs.push_back(gecici[i]);
            EV << childs.at(i)-> getPreviousGate()-> getOwner()-> getFullName() << " , ";
        }
        EV <<" katman bilgisi : "<< myLayer+1 << "\n";

    }else{
        Pack *pk=check_and_cast<Pack *>(msg);   //donusum
        if(pk->getPACKETTYPE()=='l'){

            if(incomedGate == NULL){

                parentGate=0;
                myLayer = 0; //katman 0 (kök)

                for(int i=0;i<this->gateCount()/2;i++){
                    if(pk->arrivedOn("gate$i",i)){    //eğer giris kapısından mesaj gelmişse es geçiyor
                        continue;
                    }else{

                        Pack *pkt = new Pack("child?",2);
                        pkt->setPACKETTYPE('l');
                        pkt->setLAYER(myLayer+1);
                        send(pkt,"gate$o",i);
                    }
                }
            }else{
                if(myLayer==-1 || myLayer >pk->getLAYER()){
                    if(myLayer !=-1){

                        send(INVALIDATE,"gate$o",parentGate);    //geçersiz kılmak,ebeveynlikten red
                        childs.clear();
                    }
                    parentGate=incomedGate->getIndex();
                    myLayer=pk->getLAYER();
                    send(ACK,"gate$o",parentGate);
                    for(int i = 0;i<this->gateCount()/2;i++)
                    {
                        if(msg->arrivedOn("gate$i",i)){
                            continue;
                        }else{

                            Pack *pkt = new Pack("child?",2);
                            pkt->setPACKETTYPE('l');
                            pkt->setLAYER(myLayer+1);
                            send(pkt,"gate$o",i);
                        }
                    }
                }else{
                    send(REJECT, "gate$o",incomedGate-> getIndex());
                }
            }
        }
    }
}












