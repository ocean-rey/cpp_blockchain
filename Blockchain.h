#include "Block.h"
#include <cstdint>
#include <vector>

using namespace std;

class Blockchain {
public:
  Blockchain(int difficulty);
  void AddBlock(Block bNew);

private:
  uint32_t _nDifficulty;
  vector<Block> _vChain;
  Block _GetLastBlock() const;
};
