typedef struct _SetGroupPresharedKey_IN {
  ULONG KeySize;
  UCHAR Key[1];
} SetGroupPresharedKey_IN, *PSetGroupPresharedKey_IN;