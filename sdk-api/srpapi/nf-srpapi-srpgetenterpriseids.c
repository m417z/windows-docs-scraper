HRESULT SrpGetEnterpriseIds(
  [in]                HANDLE tokenHandle,
  [in, out, optional] PULONG numberOfBytes,
  [out, optional]     PCWSTR *enterpriseIds,
  [out]               PULONG enterpriseIdCount
);