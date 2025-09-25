BOOL CreateWellKnownSid(
  [in]            WELL_KNOWN_SID_TYPE WellKnownSidType,
  [in, optional]  PSID                DomainSid,
  [out, optional] PSID                pSid,
  [in, out]       DWORD               *cbSid
);