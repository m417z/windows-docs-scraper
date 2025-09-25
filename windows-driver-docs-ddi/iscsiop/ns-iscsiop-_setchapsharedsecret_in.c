typedef struct _SetCHAPSharedSecret_IN {
  ULONG SharedSecretSize;
  UCHAR SharedSecret[1];
} SetCHAPSharedSecret_IN, *PSetCHAPSharedSecret_IN;