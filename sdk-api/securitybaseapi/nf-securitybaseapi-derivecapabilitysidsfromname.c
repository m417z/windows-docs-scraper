BOOL DeriveCapabilitySidsFromName(
  [in]  LPCWSTR CapName,
  [out] PSID    **CapabilityGroupSids,
  [out] DWORD   *CapabilityGroupSidCount,
  [out] PSID    **CapabilitySids,
  [out] DWORD   *CapabilitySidCount
);