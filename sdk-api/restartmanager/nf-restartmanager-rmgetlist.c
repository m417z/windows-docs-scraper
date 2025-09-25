DWORD RmGetList(
  [in]                DWORD              dwSessionHandle,
  [out]               UINT               *pnProcInfoNeeded,
  [in, out]           UINT               *pnProcInfo,
  [in, out, optional] RM_PROCESS_INFO [] rgAffectedApps,
  [out]               LPDWORD            lpdwRebootReasons
);