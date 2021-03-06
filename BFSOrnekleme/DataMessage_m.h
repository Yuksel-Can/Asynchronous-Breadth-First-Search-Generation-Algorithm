//
// Generated file, do not edit! Created by nedtool 5.6 from DataMessage.msg.
//

#ifndef __DATAMESSAGE_M_H
#define __DATAMESSAGE_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>DataMessage.msg:3</tt> by nedtool.
 * <pre>
 * message DataMessage
 * {
 *     int payload;
 * }
 * </pre>
 */
class DataMessage : public ::omnetpp::cMessage
{
  protected:
    int payload;

  private:
    void copy(const DataMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const DataMessage&);

  public:
    DataMessage(const char *name=nullptr, short kind=0);
    DataMessage(const DataMessage& other);
    virtual ~DataMessage();
    DataMessage& operator=(const DataMessage& other);
    virtual DataMessage *dup() const override {return new DataMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getPayload() const;
    virtual void setPayload(int payload);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DataMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DataMessage& obj) {obj.parsimUnpack(b);}


#endif // ifndef __DATAMESSAGE_M_H

