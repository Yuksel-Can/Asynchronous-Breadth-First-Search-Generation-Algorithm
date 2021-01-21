import ned.DelayChannel;

simple node
{
    @display("i=device/laptop");
    gates:
        inout gate[];
}
channel wired extends DelayChannel
{
    @display("ls=#4E9A06,2,s");
    delay = 100ms;
}
channel wireless extends DelayChannel
{
    @display("ls=#A40000,2,da");
    delay = 250ms;
}
network bfsTabanliNetwork
{
    @display("bgi=background/streetmap;bgb=594,421");
    submodules:
        node1: node {
            @display("p=117,271");
        }
        node2: node {
            @display("p=289,271");
        }
        node3: node {
            @display("p=464,271");
        }
        node4: node {
            @display("p=464,97");
        }
        node5: node {
            @display("p=289,97");
        }
        node6: node {
            @display("p=117,97");
        }
    connections:
        node6.gate++ <--> wired <--> node5.gate++;
        node5.gate++ <--> wired <--> node4.gate++;
        node6.gate++ <--> wired <--> node1.gate++;
        node5.gate++ <--> wired <--> node2.gate++;
        node5.gate++ <--> wired <--> node3.gate++;
        node6.gate++ <--> wireless <--> node2.gate++;
        node1.gate++ <--> wireless <--> node2.gate++;
        node2.gate++ <--> wireless <--> node3.gate++;
        node3.gate++ <--> wireless <--> node4.gate++;
}

