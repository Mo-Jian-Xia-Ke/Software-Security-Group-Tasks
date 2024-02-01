#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
  struct Count : public ModulePass {
    static char ID;
    Count() : ModulePass(ID) {}

    bool runOnModule(Module &M) override {
      int num_f = 0;
      int num_bb = 0;

      for (Function &F : M) {
        num_f++;
        for (BasicBlock &BB : F) {
          num_bb++;
        }
      }

      errs() << "The program has a total of " << num_f << " functions and "
             << num_bb << " basic blocks.\n";
      return false;
    }
  };
}

char Count::ID = 0;
static RegisterPass<Count> X("Count", "Count Functions and Basic Blocks Pass");