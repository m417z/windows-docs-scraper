MINIPORT_ALLOCATE_SHARED_MEM_COMPLETE MiniportAllocateSharedMemComplete;

VOID MiniportAllocateSharedMemComplete(
  [in] NDIS_HANDLE MiniportAdapterContext,
  [in] PVOID VirtualAddress,
  [in] PNDIS_PHYSICAL_ADDRESS PhysicalAddress,
  [in] ULONG Length,
  [in] PVOID Context
)
{...}