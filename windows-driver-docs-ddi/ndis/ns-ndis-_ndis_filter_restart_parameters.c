typedef struct _NDIS_FILTER_RESTART_PARAMETERS {
  NDIS_OBJECT_HEADER       Header;
  NDIS_MEDIUM              MiniportMediaType;
  NDIS_PHYSICAL_MEDIUM     MiniportPhysicalMediaType;
  PNDIS_RESTART_ATTRIBUTES RestartAttributes;
  NET_IFINDEX              LowerIfIndex;
  NET_LUID                 LowerIfNetLuid;
  ULONG                    Flags;
} NDIS_FILTER_RESTART_PARAMETERS, *PNDIS_FILTER_RESTART_PARAMETERS;