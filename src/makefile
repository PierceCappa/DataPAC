all: compile_DF compile_DFR compile_NV compile_DPD compile_DPF compile_DPST makeLibrary

compile_DF: DataFrame.cpp
	g++ -c -fpic -o DataFrame.o DataFrame.cpp 

compile_DFR: DataFrameRow.cpp
	g++ -c -fpic -o DataFrameRow.o DataFrameRow.cpp 

compile_NV: NodeValue.cpp
	g++ -c -fpic -o NodeValue.o NodeValue.cpp 

compile_DPD: DPDiscrete.cpp
	g++ -c -fpic -o DPDiscrete.o DPDiscrete.cpp 
	
compile_DPF: DPFloat.cpp
	g++ -c -fpic -o DPFloat.o DPFloat.cpp 


compile_DPST: DPString.cpp
	g++ -c -fpic -o DPString.o DPString.cpp 

makeLibrary: DataFrame.o DataFrameRow.o DPString.o DPFloat.o DPDiscrete.o NodeValue.o
	ar rvs libDataFrame.a DataFrame.o DataFrameRow.o DPString.o DPFloat.o DPDiscrete.o NodeValue.o
	

