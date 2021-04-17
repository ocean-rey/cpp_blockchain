#include "block.h"
#include <cstdint>
#include <vector>

using namespace std;

class Blockchain {
public:
  Blockchain();
  void addBlock(Block bNew);

private:
  uint32_t _nDifficulty;
  vector<Block> _vChain;
  const Block _GetLastBlock();
}
