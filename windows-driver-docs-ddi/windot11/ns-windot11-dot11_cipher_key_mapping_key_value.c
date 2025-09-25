typedef struct DOT11_CIPHER_KEY_MAPPING_KEY_VALUE {
  DOT11_MAC_ADDRESS      PeerMacAddr;
  DOT11_CIPHER_ALGORITHM AlgorithmId;
  DOT11_DIRECTION        Direction;
  BOOLEAN                bDelete;
  BOOLEAN                bStatic;
  USHORT                 usKeyLength;
  UCHAR                  ucKey[1];
} DOT11_CIPHER_KEY_MAPPING_KEY_VALUE, *PDOT11_CIPHER_KEY_MAPPING_KEY_VALUE;