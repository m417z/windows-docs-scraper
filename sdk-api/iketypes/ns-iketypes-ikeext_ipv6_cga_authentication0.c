typedef struct IKEEXT_IPV6_CGA_AUTHENTICATION0_ {
  wchar_t          *keyContainerName;
  wchar_t          *cspName;
  UINT32           cspType;
  FWP_BYTE_ARRAY16 cgaModifier;
  BYTE             cgaCollisionCount;
} IKEEXT_IPV6_CGA_AUTHENTICATION0;