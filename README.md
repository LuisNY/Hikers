# hikers

 There are 2 algorithms that can be used to solve this problem:

  1) the first is the 'obvious' one, where one hiker crosses the bridge with the fastest hiker
    and the fastest hiker then goes back to pick up a new hiker, until there are no hikers left

  2) the second is the 'classical' algorithm, where the idea is that slow hikers cross together
    to minimize the crossing time.

 There is no algorithm that will perform better in all cases, so the key of the problem is to understand what
 algorithm needs to be used according to the input values.

 However, it is noticeable that no matter what algorithm is used, there is a common number of trips that need to
 be done in both algorithms. The idea in this program is to find the minimum time required to complete the trips
 that the two algorithms have in common, and then add to this time the fastest of the remaining times calculated
 by the two different algorithms.


Dependencies
-

Need to install the dependency yaml-cpp executing the following commands:

```
sudo apt-get update
sudo apt-get install libyaml-cpp-dev
```

Build and run
-

Run the following commands to build the code:
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

The executable is in `hikers/bin/hikers_program`. Run the following (from `build` directory) to execute:
```
../bin/hikers_program
```
