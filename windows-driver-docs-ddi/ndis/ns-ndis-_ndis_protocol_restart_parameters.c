typedef struct _NDIS_PROTOCOL_RESTART_PARAMETERS {
  NDIS_OBJECT_HEADER       Header;
  PUCHAR                   FilterModuleNameBuffer;
  ULONG                    FilterModuleNameBufferLength;
  PNDIS_RESTART_ATTRIBUTES RestartAttributes;
  NET_IFINDEX              BoundIfIndex;
  NET_LUID                 BoundIfNetluid;
  ULONG                    Flags;
} NDIS_PROTOCOL_RESTART_PARAMETERS, *PNDIS_PROTOCOL_RESTART_PARAMETERS;