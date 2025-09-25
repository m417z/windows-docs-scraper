typedef struct _NDIS_PD_CONFIG {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  BOOLEAN            Enabled;
  ULONG              CapabilitiesOffset;
  ULONG              CapabilitiesSize;
} NDIS_PD_CONFIG;