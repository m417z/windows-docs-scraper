typedef struct _CRYPT_AES_128_KEY_STATE {
  unsigned char Key[16];
  unsigned char IV[16];
  unsigned char EncryptionState[11][16];
  unsigned char DecryptionState[11][16];
  unsigned char Feedback[16];
} CRYPT_AES_128_KEY_STATE, *PCRYPT_AES_128_KEY_STATE;