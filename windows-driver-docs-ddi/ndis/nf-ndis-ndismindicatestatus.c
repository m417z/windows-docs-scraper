VOID NdisMIndicateStatus(
  [in] NDIS_HANDLE MiniportHandle,
  [in] NDIS_STATUS GeneralStatus,
  [in] PVOID       StatusBuffer,
  [in] UINT        StatusBufferSize
);