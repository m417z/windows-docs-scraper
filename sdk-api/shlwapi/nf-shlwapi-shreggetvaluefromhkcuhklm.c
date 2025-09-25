LSTATUS SHRegGetValueFromHKCUHKLM(
  [in]      PCWSTR pwszKey,
  [in]      PCWSTR pwszValue,
  [in]      SRRF   srrfFlags,
  [out]     DWORD  *pdwType,
  [in]      void   *pvData,
  [in, out] DWORD  *pcbData
);