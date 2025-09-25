DWORD WlanHostedNetworkSetProperty(
  [in]            HANDLE                      hClientHandle,
  [in]            WLAN_HOSTED_NETWORK_OPCODE  OpCode,
  [in]            DWORD                       dwDataSize,
  [in]            PVOID                       pvData,
  [out, optional] PWLAN_HOSTED_NETWORK_REASON pFailReason,
                  PVOID                       pvReserved
);