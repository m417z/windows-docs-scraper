typedef struct _DOT11_ADDITIONAL_IE {
  NDIS_OBJECT_HEADER Header;
  ULONG              uBeaconIEsOffset;
  ULONG              uBeaconIEsLength;
  ULONG              uResponseIEsOffset;
  ULONG              uResponseIEsLength;
} DOT11_ADDITIONAL_IE, *PDOT11_ADDITIONAL_IE;