LSTATUS RegCreateKeyTransactedA(
  [in]            HKEY                        hKey,
  [in]            LPCSTR                      lpSubKey,
                  DWORD                       Reserved,
  [in, optional]  LPSTR                       lpClass,
  [in]            DWORD                       dwOptions,
  [in]            REGSAM                      samDesired,
  [in, optional]  const LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [out]           PHKEY                       phkResult,
  [out, optional] LPDWORD                     lpdwDisposition,
  [in]            HANDLE                      hTransaction,
                  PVOID                       pExtendedParemeter
);