ALLOCATE_SHARED_MEMORY_HANDLER AllocateSharedMemoryHandler;

NDIS_STATUS AllocateSharedMemoryHandler(
  [in]      NDIS_HANDLE ProviderContext,
  [in]      PNDIS_SHARED_MEMORY_PARAMETERS SharedMemoryParameters,
  [in, out] PNDIS_HANDLE pSharedMemoryProviderContext
)
{...}