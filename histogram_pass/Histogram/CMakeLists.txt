add_llvm_library( LLVMHistogram MODULE
  Histogram.cpp

  PLUGIN_TOOL
  opt
  )