int WlxLoggedOutSAS(
  [in]      PVOID                pWlxContext,
  [in]      DWORD                dwSasType,
  [out]     PLUID                pAuthenticationId,
  [in, out] PSID                 pLogonSid,
  [out]     PDWORD               pdwOptions,
  [out]     PHANDLE              phToken,
  [out]     PWLX_MPR_NOTIFY_INFO pNprNotifyInfo,
  [out]     PVOID                *pProfile
);