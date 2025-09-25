typedef struct _NDIS_QOS_CAPABILITIES {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  ULONG              MaxNumTrafficClasses;
  ULONG              MaxNumEtsCapableTrafficClasses;
  ULONG              MaxNumPfcEnabledTrafficClasses;
} NDIS_QOS_CAPABILITIES, *PNDIS_QOS_CAPABILITIES;