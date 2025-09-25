VOID NdisMAllocateSharedMemory(
  [in]  NDIS_HANDLE            MiniportAdapterHandle,
  [in]  ULONG                  Length,
  [in]  BOOLEAN                Cached,
  [out] PVOID                  *VirtualAddress,
  [out] PNDIS_PHYSICAL_ADDRESS PhysicalAddress
);