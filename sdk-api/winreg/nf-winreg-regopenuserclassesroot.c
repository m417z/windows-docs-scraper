LSTATUS RegOpenUserClassesRoot(
  [in]  HANDLE hToken,
        DWORD  dwOptions,
  [in]  REGSAM samDesired,
  [out] PHKEY  phkResult
);