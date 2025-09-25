DWORD WlanQueryAutoConfigParameter(
  [in]            HANDLE                  hClientHandle,
  [in]            WLAN_AUTOCONF_OPCODE    OpCode,
                  PVOID                   pReserved,
  [out]           PDWORD                  pdwDataSize,
  [out]           PVOID                   *ppData,
  [out, optional] PWLAN_OPCODE_VALUE_TYPE pWlanOpcodeValueType
);