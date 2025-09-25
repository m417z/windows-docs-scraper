typedef struct _NDIS_SWITCH_PROPERTY_CUSTOM {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  ULONG              PropertyBufferLength;
  ULONG              PropertyBufferOffset;
} NDIS_SWITCH_PROPERTY_CUSTOM, *PNDIS_SWITCH_PROPERTY_CUSTOM;