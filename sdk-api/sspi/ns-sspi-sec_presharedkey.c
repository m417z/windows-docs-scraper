typedef struct _SEC_PRESHAREDKEY {
  unsigned short KeySize;
  unsigned char  Key[ANYSIZE_ARRAY];
} SEC_PRESHAREDKEY, *PSEC_PRESHAREDKEY;