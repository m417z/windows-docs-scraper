typedef struct _NDIS_NDK_CONNECTIONS {
  NDIS_OBJECT_HEADER        Header;
  ULONG                     Flags;
  ULONG                     Count;
  BOOLEAN                   NDConnectionsMappedtoTCPConnections;
  NDIS_NDK_CONNECTION_ENTRY Connections[1];
} NDIS_NDK_CONNECTIONS;