WINHTTPAPI DWORD WinHttpQueryConnectionGroup(
  HINTERNET                              hInternet,
  const GUID                             *pGuidConnection,
  ULONGLONG                              ullFlags,
  PWINHTTP_QUERY_CONNECTION_GROUP_RESULT *ppResult
);