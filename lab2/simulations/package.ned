package lab2.simulations;

import lab2.Player1;
import lab2.Player2;


@license(LGPL);
//
// TODO documentation
//
network guessingGame
{
    @display("bgb=726,343");
    types:
    submodules:
        player1: Player1 {
            @display("p=147,132");
        }
        player2: Player2 {
            @display("p=468,132");
        }
    connections:
        player1.out --> player2.in;
        player2.out --> player1.in;
}

