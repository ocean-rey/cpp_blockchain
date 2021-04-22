#include "Block.h"
#include "sha256.h"
#include <chrono> // so we can time our function
#include <sstream>

using namespace std::chrono;

Block::Block(uint32_t nIndexIn, const string &sDataIn)
    : _nIndex(nIndexIn), _sData(sDataIn) {
  _nNonce = -1;
  _tTime = time(nullptr);
}

string Block::GetHash() { return _sHash; }

void Block::MineBlock(uint32_t nDifficulty) {
  // init timer here
  auto start = high_resolution_clock::now();
  char cstr[nDifficulty + 1];
  float khs = 0;
  for (uint32_t i = 0; i < nDifficulty; ++i) {
    cstr[i] = '0';
  }
  cstr[nDifficulty] = '\0';
  string str(cstr);
  do {
    _nNonce++;
    _sHash = _CalculateHash();
  } while (_sHash.substr(0, nDifficulty) != str);
  cout << "Block mined:\t" << _sHash << endl;
  auto stop = high_resolution_clock::now();                  // init stop
  auto duration = duration_cast<microseconds>(stop - start); // init duration
  auto time = duration.count();    // get duration in microseconds
  float kilohash = _nNonce / 1000; // calculate kH/s
  cout << "Difficulty:\t" << nDifficulty << endl;
  cout << time << endl;
  khs = (kilohash / time) *
        1000000; // mutliply by 10^6 to convert from kH/microseconds to kH/s
  cout << "kH/s:\t" << khs << endl;
}

inline string Block::_CalculateHash() const {
  std::stringstream ss;
  ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;
  return sha256(ss.str());
}
