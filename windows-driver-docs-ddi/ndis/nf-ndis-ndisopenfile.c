VOID NdisOpenFile(
  [out] PNDIS_STATUS          Status,
  [out] PNDIS_HANDLE          FileHandle,
  [out] PUINT                 FileLength,
  [in]  PNDIS_STRING          FileName,
  [in]  NDIS_PHYSICAL_ADDRESS HighestAcceptableAddress
);