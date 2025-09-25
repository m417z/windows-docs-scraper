DWORD WlanQueryInterface(
  [in]            HANDLE                  hClientHandle,
  [in]            const GUID              *pInterfaceGuid,
  [in]            WLAN_INTF_OPCODE        OpCode,
                  PVOID                   pReserved,
  [out]           PDWORD                  pdwDataSize,
  [out]           PVOID                   *ppData,
  [out, optional] PWLAN_OPCODE_VALUE_TYPE pWlanOpcodeValueType
);