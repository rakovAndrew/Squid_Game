# Squid_Game

> This is the first laboratory work using ROS. 

---

### Task

- I have the <ins>**third variant**</ins>, so I made a Squid Game prototype. 
- The game receives the following symbols as input: '_l_' and '_r_'.
- If the symbol is similar to a certain symbol of the path, the game returns "_Good choice... Let's go to the next one!_" and _the path that you have made_.
- If the symbol is not similar to a certain symbol of the path, the game returns "_You are dead_" and **shuts down the server node**.
- All right messages are saved in "_game_topic_" topic. 
- If the path that you have made is similar to the game path, you will receive the message: "_You won, little piece of shit!.._".

---

### How to play

#### In the first terminal:

1. Clone this project.
2. Go to your project directory.
3. Build the project using <pre>catkin_make</pre>
4. You **must** have a <ins>roscore</ins> running in order for ROS nodes to communicate. It is launched using the following command <pre>roscore</pre>

#### In the second terminal

1. Go to your project directory.
2. You need to run <ins>setup.bash</ins> file to add environment variables to your path to allow ROS to function. Run in with the next command <pre>source devel/setup.bash</pre>
3. Run the server that will process your requests. Use this command <pre>rosrun first_laboratory_work subscriber</pre>

#### In the third terminal

1. Use this command to see messages in the topic <pre>rostopic echo /game_topic</pre>

#### In the fourth terminal

1. Use this command to call the service to play the game <pre>rosservice call /path_to_win "turn: <ins>''</ins>"</pre> 
You have to input your variant of the turn variable in single quotes that are underlined. You have to use '_l_' / '_left_' or '_r_' / '_right_'.