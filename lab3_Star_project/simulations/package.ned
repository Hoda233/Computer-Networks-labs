package star_project.simulations;

import star_project.Node;
import star_project.Hub;

@license(LGPL);
//
// TODO documentation
//
network Network
{
    parameters:
        int N = default(4);

        
    submodules:
        nodes[N]: Node;
        hub: Hub {
        }
    connections:
        for i=0..N-1 {
            nodes[i].port <--> hub.ports++;
        }
}

