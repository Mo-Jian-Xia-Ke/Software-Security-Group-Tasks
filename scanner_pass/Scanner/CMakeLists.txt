add_llvm_library( LLVMScanner MODULE
  Scanner.cpp

  PLUGIN_TOOL
  opt
  )