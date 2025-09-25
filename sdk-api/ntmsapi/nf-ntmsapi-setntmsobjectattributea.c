DWORD SetNtmsObjectAttributeA(
  [in] HANDLE      hSession,
  [in] LPNTMS_GUID lpObjectId,
  [in] DWORD       dwType,
  [in] LPCSTR      lpAttributeName,
  [in] LPVOID      lpAttributeData,
  [in] DWORD       dwAttributeSize
);