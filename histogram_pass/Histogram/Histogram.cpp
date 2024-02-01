#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/Support/raw_ostream.h"

#include <map>

using namespace llvm;

namespace {
  struct Histogram : public FunctionPass {
    static char ID;
    Histogram() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      std::map<int, int> histogram;

      for (BasicBlock &BB : F) {
        int num_i = 0;
        for (Instruction &I : BB) {
          num_i++;
        }
        histogram[num_i]++;
      }

      for (auto &entry : histogram) {
        outs() << entry.first << ": " << entry.second << "\n";
      }

      return false;
    }
  };
}

char Histogram::ID = 0;
static RegisterPass<Histogram> X("histogram", "Generate Histogram of Instructions in Basic Blocks");