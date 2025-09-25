typedef struct _DOT11_WFD_ADDITIONAL_IE {
  NDIS_OBJECT_HEADER Header;
  ULONG              uBeaconIEsOffset;
  ULONG              uBeaconIEsLength;
  ULONG              uProbeResponseIEsOffset;
  ULONG              uProbeResponseIEsLength;
  ULONG              uDefaultRequestIEsOffset;
  ULONG              uDefaultRequestIEsLength;
}  DOT11_WFD_ADDITIONAL_IE, *PDOT11_WFD_ADDITIONAL_IE;