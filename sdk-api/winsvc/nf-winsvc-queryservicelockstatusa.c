BOOL QueryServiceLockStatusA(
  [in]            SC_HANDLE                    hSCManager,
  [out, optional] LPQUERY_SERVICE_LOCK_STATUSA lpLockStatus,
  [in]            DWORD                        cbBufSize,
  [out]           LPDWORD                      pcbBytesNeeded
);