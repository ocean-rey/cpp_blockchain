#include "Blockchain.h"
#include <iostream>
#include <sstream>

int main() {
  Blockchain bChain = Blockchain(4);
  int i = 2;
  do {
    bChain.AddBlock(Block(i, "some data"));
    // bChain.IncDiff();
    i++;
  } while (true);
  return 0;
}
