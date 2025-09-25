VOID NdisMGetVirtualFunctionLocation(
  [in]  NDIS_HANDLE            NdisMiniportHandle,
  [in]  NDIS_SRIOV_FUNCTION_ID VFId,
  [out] PUSHORT                SegmentNumber,
  [out] PUCHAR                 BusNumber,
  [out] PUCHAR                 FunctionNumber
);