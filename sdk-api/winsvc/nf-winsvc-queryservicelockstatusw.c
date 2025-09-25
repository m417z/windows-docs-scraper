BOOL QueryServiceLockStatusW(
  [in]            SC_HANDLE                    hSCManager,
  [out, optional] LPQUERY_SERVICE_LOCK_STATUSW lpLockStatus,
  [in]            DWORD                        cbBufSize,
  [out]           LPDWORD                      pcbBytesNeeded
);