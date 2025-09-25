typedef struct _SecPkgContext_NegoKeys {
  unsigned long  KeyType;
  unsigned short KeyLength;
  unsigned char  *KeyValue;
  unsigned long  VerifyKeyType;
  unsigned short VerifyKeyLength;
  unsigned char  *VerifyKeyValue;
} SecPkgContext_NegoKeys, *PSecPkgContext_NegoKeys;