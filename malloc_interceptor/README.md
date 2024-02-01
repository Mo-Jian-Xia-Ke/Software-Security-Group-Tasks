# Malloc Interceptor

Steps to build and run the malloc interceptor:
1. Compile the malloc_interceptor.c file into a shared library:  
  `gcc -shared -fPIC -o malloc.so malloc_interceptor.c -ldl`  
  (where -ldl tells the linker to link against the dynamic loading library,
   since we are using dlsym() to dynamically retrieve symbols at runtime.)

2. Set the LD_PRELOAD environment variable to load the library before running the program:  
  `LD_PRELOAD=./malloc.so ./your_program`  
  Replace "your_program" with the name of the program you want to run.
