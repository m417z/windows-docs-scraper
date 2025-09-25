NDIS_STATUS NdisMMapIoSpace(
  [out] PVOID                 *VirtualAddress,
  [in]  NDIS_HANDLE           MiniportAdapterHandle,
  [in]  NDIS_PHYSICAL_ADDRESS PhysicalAddress,
  [in]  UINT                  Length
);