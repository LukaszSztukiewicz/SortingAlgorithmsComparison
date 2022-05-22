#!/bin/bash

projectname="$1"

#TODO create folder structure


#add dependencies
cd lib && git clone https://github.com/google/googletest.git

#run build
cd ../
cmake .
make

#TODO write shortcuts
echo "prun (){
    ./build/${projectname}_run
}
export -f prun" >> ~/.bashrc

echo "ptest (){
    ./build/${projectname}_test
}
export -f ptest" >> ~/.bashrc