#include <cstdint>
#include <iostream>

using namespace std;

class Block {
public:
  string sPrevHash;
  Block(uint32_t nIndexIn, const sting &sDataIn);
  string GetHash();
  void MineBlock(uint32_t nDifficulty);

private:
  uint32_t _nIndex;
  int64_t _nNonce;
  string _sData;
  string _sHash;
  time_t _tTime;
  const string _CalculateHash();
}
