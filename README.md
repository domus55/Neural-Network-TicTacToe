# Neural-Network-TicTacToe

![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/1.png) 

There are 4 difficulties we can train network on:
* easy - places circle on random field, it's really easy for human, but neural network have huge problem to learn how to win
* medium - tries to place a circle in the middle or corners
* hard - tries to make a line
* almost impossible - tries to make a line, can see when neural network have two crosses in row

Neural network is built from input layer with 18 neurons matching fields for every player, 2 hidden layers with 12 neurons
and output with 9 neurons matching every field.

## Against hard bot
At the beggining cross have 24% winrate
![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/2.png)

After 5 seconds we already can see 81% winrate
![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/3.png)

After further 30 seconds neural network will win every game
![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/4.png)

## If we choose the almost impossible difficulty instead
At the beginning neural network have only 0.8% winrate
![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/5.png)

But the score improves with time
Result after 10 seconds
![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/6.png)

Result after 30 seconds
![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/7.png)

Result after 5 minutes
![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/8.png)

## We can see the game by clicking 'p'
![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/9.png)
![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/10.png)
![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/11.png)
![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/12.png)
![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/13.png)
![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/14.png)
![alt text](https://github.com/domus55/Neural-Network-TicTacToe/blob/master/TicTacToe/Images/15.png)

# Summary
|Time|0 seconds|5 seconds|30 seconds|5 minutes|
|---|---|---|---|---|
|Easy|Winrate: 43.7%|49.2%|74.5%|82.4%|
|Medium|Winrate: 24.6%|95%|100%|100%|
|Hard|Winrate: 24%|81%|100%|100%|
|Almost impossible|Winrate: 0.8%|1.9%|5.7%|16.8%

