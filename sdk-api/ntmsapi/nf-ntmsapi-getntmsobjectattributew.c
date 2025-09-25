DWORD GetNtmsObjectAttributeW(
  [in]      HANDLE      hSession,
  [in]      LPNTMS_GUID lpObjectId,
  [in]      DWORD       dwType,
  [in]      LPCWSTR     lpAttributeName,
  [out]     LPVOID      lpAttributeData,
  [in, out] LPDWORD     lpAttributeSize
);