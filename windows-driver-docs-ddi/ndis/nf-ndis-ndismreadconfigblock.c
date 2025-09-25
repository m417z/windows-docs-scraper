NDIS_STATUS NdisMReadConfigBlock(
  [in]  NDIS_HANDLE NdisMiniportHandle,
  [in]  ULONG       BlockId,
  [out] PVOID       Buffer,
  [in]  ULONG       Length
);