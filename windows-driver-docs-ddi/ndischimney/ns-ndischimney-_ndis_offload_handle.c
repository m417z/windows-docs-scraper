typedef struct _NDIS_OFFLOAD_HANDLE {
  PVOID NdisReserved[1];
  PVOID MiniportOffloadContext;
} NDIS_OFFLOAD_HANDLE, *PNDIS_OFFLOAD_HANDLE;