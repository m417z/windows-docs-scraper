typedef struct _NDIS_MINIPORT_OFFLOAD_BLOCK_LIST {
  IN NDIS_OBJECT_HEADER                Header;
  IN _NDIS_MINIPORT_OFFLOAD_BLOCK_LIST *NextBlock;
#if ...
  struct                               _NDIS_MINIPORT_OFFLOAD_BLOCK_LIST;
  IN _NDIS_MINIPORT_OFFLOAD_BLOCK_LIST *DependentBlockList;
#else
  struct                               _NDIS_MINIPORT_OFFLOAD_BLOCK_LIST;
#endif
  OUT NDIS_STATUS                      Status;
  IN PVOID                             NdisReserved[2];
  IN OUT PVOID                         *MiniportOffloadContext;
  IN NDIS_HANDLE                       NdisOffloadHandle;
  IN PVOID                             ProtocolReserved[2];
  IN PVOID                             MiniportReserved[2];
  IN PVOID                             ImReserved[2];
  IN PVOID                             Scratch[2];
  IN PVOID                             SourceHandle;
  IN NDIS_PORT_NUMBER                  PortNumber;
  IN OUT PNET_BUFFER_LIST              NetBufferListChain;
} NDIS_MINIPORT_OFFLOAD_BLOCK_LIST, *PNDIS_MINIPORT_OFFLOAD_BLOCK_LIST;