typedef struct _PKTMON_COMP_PROPERTY_IN {
  PKTMON_HEADER                Header;
  PKTMON_COMPONENT_PROPERTY_ID Id;
  const VOID                   *Value;
  USHORT                       Size;
} PKTMON_COMP_PROPERTY_IN;