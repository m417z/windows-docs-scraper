NTSTATUS LsaQueryCAPs(
        PSID                   *CAPIDs,
  [in]  ULONG                  CAPIDCount,
  [out] PCENTRAL_ACCESS_POLICY *CAPs,
  [out] PULONG                 CAPCount
);