package lab4;

@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=642,287");
    submodules:
        sender: Sender {
            @display("p=137,101");
        }
        receiver: Receiver {
            @display("p=345,101");
        }
    connections:
        sender.out --> receiver.in;
        receiver.out --> sender.in;
}

