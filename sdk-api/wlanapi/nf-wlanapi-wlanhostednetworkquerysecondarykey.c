DWORD WlanHostedNetworkQuerySecondaryKey(
  [in]            HANDLE                      hClientHandle,
  [out]           PDWORD                      pdwKeyLength,
  [out]           PUCHAR                      *ppucKeyData,
  [out]           PBOOL                       pbIsPassPhrase,
  [out]           PBOOL                       pbPersistent,
  [out, optional] PWLAN_HOSTED_NETWORK_REASON pFailReason,
                  PVOID                       pvReserved
);