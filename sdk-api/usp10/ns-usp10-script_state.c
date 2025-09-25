typedef struct tag_SCRIPT_STATE {
  WORD uBidiLevel : 5;
  WORD fOverrideDirection : 1;
  WORD fInhibitSymSwap : 1;
  WORD fCharShape : 1;
  WORD fDigitSubstitute : 1;
  WORD fInhibitLigate : 1;
  WORD fDisplayZWG : 1;
  WORD fArabicNumContext : 1;
  WORD fGcpClusters : 1;
  WORD fReserved : 1;
  WORD fEngineReserved : 2;
} SCRIPT_STATE;