package lab1;

@license(LGPL);
//
// TODO documentation
//
network test
{
    @display("bgb=556,336");
    types:
    submodules:
        Tic: Node {
            @display("p=102,151");
        }
        Toc: Node {
            @display("p=377,151");
        }
    connections:
        Tic.out --> Toc.in;
        Toc.out --> Tic.in;
}

