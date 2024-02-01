# Count Pass

Steps to build and run the count pass:
1. Put the whole "Count" folder under the path: llvm-project/llvm/lib

2. Add the following line into lib/CMakeLists.txt:  
  `add_subdirectory(Count)`

3. Compile the file with a simple "gmake" command from the top level of your build directory.  
   Now we should get a new file "lib/LLVMCount.so".

4. Assume we now have the LLVM bitcode version of the target program, "program.bc".  
   If not, create one using the following command:  
  `clang -c -emit-llvm program.c`

5. Now we can run our pass on the given program:  
  `opt -load lib/LLVMCount.so -count < program.bc > /dev/null`

(p.s. The required clang and llvm version is too high for my windows WSL, 
 while lab machine reports "disk quota exceeded" when cloning the llvm-project,
 therefore I have not had a chance to completely test this method's correctness.
 I did my best to follow the guide and build a similar pass to achieve the goal. :(
)
