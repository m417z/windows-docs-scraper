DWORD EnumerateNtmsObject(
  [in]      HANDLE            hSession,
  [in]      const LPNTMS_GUID lpContainerId,
  [out]     LPNTMS_GUID       lpList,
  [in, out] LPDWORD           lpdwListSize,
  [in]      DWORD             dwType,
  [in]      DWORD             dwOptions
);