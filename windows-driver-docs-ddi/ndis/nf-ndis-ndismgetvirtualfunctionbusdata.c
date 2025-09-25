ULONG NdisMGetVirtualFunctionBusData(
  [in]  NDIS_HANDLE            NdisMiniportHandle,
  [in]  NDIS_SRIOV_FUNCTION_ID VFId,
  [out] PVOID                  Buffer,
  [in]  ULONG                  Offset,
  [in]  ULONG                  Length
);