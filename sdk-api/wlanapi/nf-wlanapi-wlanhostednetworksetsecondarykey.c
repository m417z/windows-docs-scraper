DWORD WlanHostedNetworkSetSecondaryKey(
  [in]            HANDLE                      hClientHandle,
  [in]            DWORD                       dwKeyLength,
  [in]            PUCHAR                      pucKeyData,
  [in]            BOOL                        bIsPassPhrase,
  [in]            BOOL                        bPersistent,
  [out, optional] PWLAN_HOSTED_NETWORK_REASON pFailReason,
                  PVOID                       pvReserved
);