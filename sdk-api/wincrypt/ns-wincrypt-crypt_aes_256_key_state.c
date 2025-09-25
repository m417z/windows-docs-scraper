typedef struct _CRYPT_AES_256_KEY_STATE {
  unsigned char Key[32];
  unsigned char IV[16];
  unsigned char EncryptionState[15][16];
  unsigned char DecryptionState[15][16];
  unsigned char Feedback[16];
} CRYPT_AES_256_KEY_STATE, *PCRYPT_AES_256_KEY_STATE;