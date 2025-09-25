NTSTATUS FwpmSubLayerEnum0(
  [in]  HANDLE         engineHandle,
  [in]  HANDLE         enumHandle,
  [in]  UINT32         numEntriesRequested,
  [out] FWPM_SUBLAYER0 ***entries,
  [out] UINT32         *numEntriesReturned
);