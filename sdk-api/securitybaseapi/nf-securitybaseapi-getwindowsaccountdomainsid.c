BOOL GetWindowsAccountDomainSid(
  [in]            PSID  pSid,
  [out, optional] PSID  pDomainSid,
  [in, out]       DWORD *cbDomainSid
);