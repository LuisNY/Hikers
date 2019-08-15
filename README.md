# Hikers

There are 2 algorithms that can be used to solve this problem:

1) The first is the 'obvious' algorithm, where any hiker crosses the bridge with the fastest hiker and the torch, then the fastest hiker goes back with the torch to pick up a new hiker, until there are no hikers left.

2) The second is the 'classical' algorithm, where slow hikers cross together to minimize the crossing time. At the beginning the two fastest hikers cross together, the fastest goes back bringing the torch with him and leaving the second fastest hiker on the other side; then the two slowest cross together with the torch and the second fastest (who had remained at the opposite side of the bridge) comes back with the torch. And we repeat this: the two fastest cross together, the fastest goes back, the two slowest remaining hikers cross together, the second fastest goes back... and so on, until all hikers have crossed. 

There is no algorithm that will perform better in all cases, so the key of the problem is to understand what algorithm needs to be used according to the input values.

However, it is noticeable that no matter what algorithm is used, there is a common number of trips that need to be done in both algorithms. The idea in this program is to find the minimum time required to complete the trips that the two algorithms have in common, and then add to this time the fastest of the remaining times calculated by the two different algorithms.

For example, let's say we have a sorted vector of floats, where each element is the time required by a hiker to cross the bridge. Since the vector is sorted, the first element represents the fastest hiker (minimum time to cross).

`[1,2,5,10]` 

Following the 'classical' algorithm the trips are shown below. The numbers in parenthesis are the hikers moving in the direction of the arrow, while the number outside the parenthesis is the time taken for the crossing. The numbers outside of the "|" keep track of the hikers on either side of the bridge.
```
5,10 | (1,2)  2  ->     | 
5,10 |           <-  1  | 2
1    | (5,10) 10 ->     | 2
1    |           <-  2  | 5,10
     | (1,2)  2  ->     | 5,10
```  

Following the 'obvious' algorithm the trips will be:
```
5,10 | (1,2)  2  ->     | 
5,10 |           <-  1  | 2
10   | (1,5)  5  ->     | 2
10   |           <-  1  | 2,5
     | (1,10) 10 ->     | 2,5
```

In both algorithms hikers 1, 2, and 10 cross at least once, making their sum the "common minimum time" (CMT) taken to cross the bridge by the hikers. CMT follows the equation below:

CMT = vector[second] + vector[last] + vector[first] + vector[last - 2] + vector[first] + vector[last - 4] + vector[first] + .... as long as `last - n > second` 

The remaining time obtained using the 'classical' algorithm (RTc) follows the equation:

RTc = vector[second] * factor

where `factor = last-second` if (last-second) is even otherwise `factor = last-second-1`

The remaining time obtained using the 'obvious' algorithm (RTo) follows the equation:

RTo = vector[last-1] + vector[first] + vector[last - 3] + vector[first] + vector[last - 5] + vector[first] + ... as long as `last - n > second`

The fastest time = `CMT + min(RTc, RTo)`

Dependencies
-

Need to install the dependency `yaml-cpp` executing the following commands:

```
sudo apt-get update
sudo apt-get install libyaml-cpp-dev
```

Build and run
-

Run the following commands to build the code (from `Hikers` directory):
```
mkdir build
cd build
cmake ..
make
```

Run the following command to run the unit tests (from `build` directory):
```
make check
```

The executable is in `path_to_Hikers/Hikers/bin/hikers_program`. Run the following to execute:
```
./path_to_Hikers/Hikers/bin/hikers_program
```
As the program starts you will be asked to insert the path to the input .yaml file to parse. 
An example file is located in `Hikers` directory.
