DWORD SetNtmsObjectAttributeW(
  [in] HANDLE      hSession,
  [in] LPNTMS_GUID lpObjectId,
  [in] DWORD       dwType,
  [in] LPCWSTR     lpAttributeName,
  [in] LPVOID      lpAttributeData,
       DWORD       AttributeSize
);