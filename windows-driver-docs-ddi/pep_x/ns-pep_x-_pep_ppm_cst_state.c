typedef struct _PEP_PPM_CST_STATE {
  UCHAR            Type;
  USHORT           Latency;
  ULONG            Power;
  UCHAR            AddressSpaceId;
  UCHAR            BitWidth;
  UCHAR            BitOffset;
  UCHAR            AccessSize;
  PHYSICAL_ADDRESS Address;
} PEP_PPM_CST_STATE, *PPEP_PPM_CST_STATE;