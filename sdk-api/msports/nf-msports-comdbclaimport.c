LONG ComDBClaimPort(
  [in]            HCOMDB HComDB,
  [in]            DWORD  ComNumber,
  [in]            BOOL   ForceClaim,
  [out, optional] PBOOL  Forced
);