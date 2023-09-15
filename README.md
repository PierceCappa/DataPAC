<H1 style="text-align: center;"> Data Frame PAC: A C++ Data Frame Library </H1> 

----
The intended purpose of this library is to provide basic data frame functionality at the highest performance.

**Description**: DataPAC is a collection of 3 libraries. DFPAC is a multithreaded dataframe library (Semi TODO), ALPAC is a data analytics library (TODO), MLPAC is a machine learning library. All libraries can be used seperatly but are designed to be used together. 

## Dependencies

Right now this project is designed to be installed on and used on the official Ubuntu image found below. This should work on any linux distro and install, but it is untested so good luck. You should also install standard c++ libraries such as g++.
https://hub.docker.com/_/ubuntu 

# Installation
## Development Environment
 * Install Docker and run the following image: https://hub.docker.com/_/ubuntu 
 * ssh into your container, I suggest using the remote - ssh extension for VS Code.
 * Install NVIDA drivers and Cuda Toolkit using the following guide: https://docs.omnisci.com/v5.2.2/4_docker_gpu_os_apt_recipe.html 
 * Clone this repo and type ./Install_Test.sh in the root project directory to compile, test, and install the project.

---

## Usage

All objects and methods in this library are under the DataPAC namespace.
Currently only the DataFrame portion of this project is even kind of implimented.
At some point I will write a wiki/manual. Until then get wild with it.

## How to test the software

Running the Install_Test.sh bash script will run tests on all parts of the project. If tests pass for a library than all tests passed will be outputted to the console.

## Known issues

Right now only like 20% of the planned project is implimented. And what is here is not very good :C.

## Getting help

If you need help, go to the discussion board and create a new discussion topic.

## Getting involved

If you want to add/refine features create an issue on the board associated with your goal. Your issue should contain a detailed description of what you changed, and why. To merge your changes onto a realease build you must first push your changes to a new branch with the format [issue #]/[description] (43/Improving_Multi_Threading). Before creating a merge request, ensure that all tests are passing and your branch is building correctly. After pushing make a merge request to master. After a couple of new features have been implimented a new release branch will be created. 

## Open source licensing info
MIT (https://github.com/PierceCappa/DataPAC/blob/master/license.txt)

<H1 style="text-align: center;"> Project Version: -0.1 </H1>


C:\"Program Files"\"Microsoft Visual Studio"\2022\Community\VC\Tools\MSVC\14.34.31933\bin\Hostx64\x64

nvcc -o Test.exe Test_DF.cpp -ccbin C:\"Program Files"\"Microsoft Visual Studio"\2022\Community\VC\Tools\MSVC\14.16.27023\bin\HostX64\x86