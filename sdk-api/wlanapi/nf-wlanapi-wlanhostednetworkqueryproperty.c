DWORD WlanHostedNetworkQueryProperty(
  [in]  HANDLE                     hClientHandle,
  [in]  WLAN_HOSTED_NETWORK_OPCODE OpCode,
  [out] PDWORD                     pdwDataSize,
  [out] PVOID                      *ppvData,
  [out] PWLAN_OPCODE_VALUE_TYPE    pWlanOpcodeValueType,
        PVOID                      pvReserved
);