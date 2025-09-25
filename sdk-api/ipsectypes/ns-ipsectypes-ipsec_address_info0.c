typedef struct IPSEC_ADDRESS_INFO0_ {
  UINT32           numV4Addresses;
  UINT32           *v4Addresses;
  UINT32           numV6Addresses;
  FWP_BYTE_ARRAY16 *v6Addresses;
} IPSEC_ADDRESS_INFO0;