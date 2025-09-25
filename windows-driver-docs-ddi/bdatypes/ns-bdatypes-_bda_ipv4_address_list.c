typedef struct _BDA_IPv4_ADDRESS_LIST {
  ULONG            ulcAddresses;
  BDA_IPv4_ADDRESS rgAddressl[MIN_DIMENSION];
} BDA_IPv4_ADDRESS_LIST, *PBDA_IPv4_ADDRESS_LIST;