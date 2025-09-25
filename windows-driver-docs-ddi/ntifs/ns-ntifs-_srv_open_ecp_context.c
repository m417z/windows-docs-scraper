typedef struct _SRV_OPEN_ECP_CONTEXT {
  PUNICODE_STRING       ShareName;
  PSOCKADDR_STORAGE_NFS SocketAddress;
  BOOLEAN               OplockBlockState;
  BOOLEAN               OplockAppState;
  BOOLEAN               OplockFinalState;
  USHORT                Version;
  SRV_INSTANCE_TYPE     InstanceType;
} SRV_OPEN_ECP_CONTEXT, *PSRV_OPEN_ECP_CONTEXT;