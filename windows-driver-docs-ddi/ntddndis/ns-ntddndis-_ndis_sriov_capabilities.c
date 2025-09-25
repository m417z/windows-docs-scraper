typedef struct _NDIS_SRIOV_CAPABILITIES {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  ULONG              SriovCapabilities;
} NDIS_SRIOV_CAPABILITIES, *PNDIS_SRIOV_CAPABILITIES;