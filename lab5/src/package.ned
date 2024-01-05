package lab5;

@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=850,246");
    submodules:
        sender: Sender {
            @display("p=187,116");
        }
        receiver: Receiver {
            @display("p=658,116");
        }
    connections:
        sender.out --> receiver.in;
        receiver.out --> sender.in;
}

