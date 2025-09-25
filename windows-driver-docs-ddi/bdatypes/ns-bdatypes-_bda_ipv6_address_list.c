typedef struct _BDA_IPv6_ADDRESS_LIST {
  ULONG            ulcAddresses;
  BDA_IPv6_ADDRESS rgAddressl[MIN_DIMENSION];
} BDA_IPv6_ADDRESS_LIST, *PBDA_IPv6_ADDRESS_LIST;