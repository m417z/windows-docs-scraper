BOOL CheckTokenCapability(
  [in, optional] HANDLE TokenHandle,
  [in]           PSID   CapabilitySidToCheck,
  [out]          PBOOL  HasCapability
);