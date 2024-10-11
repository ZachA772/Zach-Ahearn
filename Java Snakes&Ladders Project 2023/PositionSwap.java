public class PositionSwap 
{
    public void swapPositions(EncapPlayer player1, EncapPlayer player2) {
        int temp = player1.getPosition();
        player1.setPosition(player2.getPosition());
        player2.setPosition(temp);
    }
}
