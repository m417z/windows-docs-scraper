VOID NdisMFreeSharedMemory(
  [in] NDIS_HANDLE           MiniportAdapterHandle,
  [in] ULONG                 Length,
  [in] BOOLEAN               Cached,
  [in] PVOID                 VirtualAddress,
  [in] NDIS_PHYSICAL_ADDRESS PhysicalAddress
);