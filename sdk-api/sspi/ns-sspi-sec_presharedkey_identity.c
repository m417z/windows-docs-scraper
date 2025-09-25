typedef struct _SEC_PRESHAREDKEY_IDENTITY {
  unsigned short KeyIdentitySize;
  unsigned char  KeyIdentity[ANYSIZE_ARRAY];
} SEC_PRESHAREDKEY_IDENTITY, *PSEC_PRESHAREDKEY_IDENTITY;