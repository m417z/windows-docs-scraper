DWORD GetNtmsObjectAttributeA(
  [in]      HANDLE      hSession,
  [in]      LPNTMS_GUID lpObjectId,
  [in]      DWORD       dwType,
  [in]      LPCSTR      lpAttributeName,
  [out]     LPVOID      lpAttributeData,
  [in, out] LPDWORD     lpAttributeSize
);