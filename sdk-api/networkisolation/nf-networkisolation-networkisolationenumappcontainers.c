DWORD NetworkIsolationEnumAppContainers(
  [in]  DWORD                        Flags,
  [out] DWORD                        *pdwNumPublicAppCs,
  [out] PINET_FIREWALL_APP_CONTAINER *ppPublicAppCs
);