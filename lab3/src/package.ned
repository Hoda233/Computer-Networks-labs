package lab3;

@license(LGPL);

network Network
{
    parameters:
        int N = default(4);

    submodules:
        nodes[N]: Node {
//            @display("p=418,206");
        }
    connections:
        for i=0..N-1 {
            nodes[i].port++ <--> nodes[i+1].port++ if i<N-1;
            nodes[i].port++ <--> nodes[0].port++ if i== N-1;


        }



}
