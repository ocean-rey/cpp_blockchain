#include "Blockchain.h"

Blockchain::Blockchain(int difficulty) {
  _vChain.emplace_back(Block(0, "Genesis Block"));
  _nDifficulty = difficulty;
}

void Blockchain::AddBlock(Block bNew) {
  bNew.sPrevHash = _GetLastBlock().GetHash();
  bNew.MineBlock(_nDifficulty);
  _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const { return _vChain.back(); }
