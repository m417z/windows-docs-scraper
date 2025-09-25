DWORD WlanExtractPsdIEDataList(
  [in]  HANDLE              hClientHandle,
  [in]  DWORD               dwIeDataSize,
  [in]  const PBYTE         pRawIeData,
  [in]  LPCWSTR             strFormat,
        PVOID               pReserved,
  [out] PWLAN_RAW_DATA_LIST *ppPsdIEDataList
);