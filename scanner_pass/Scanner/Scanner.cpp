#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {
  struct Scanner : public ModulePass {
    static char ID;
        
    Scanner() : ModulePass(ID) {}

    bool runOnModule(Module &M) override {
      int num_f = 0;
      int num_bb = 0;

      for (auto &F : M) {
        num_f++;
        for (auto &BB : F) {
          num_bb++;
        }
      }

      errs() << "The program has a total of " << num_f << " functions and "
             << num_bb << " basic blocks.\n";
      return false;
    }
  };
}

char Scanner::ID = 0;
static RegisterPass<Scanner> X("scanner", "Scanner");