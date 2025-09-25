DWORD WlanSetInterface(
  [in] HANDLE           hClientHandle,
  [in] const GUID       *pInterfaceGuid,
  [in] WLAN_INTF_OPCODE OpCode,
  [in] DWORD            dwDataSize,
  [in] const PVOID      pData,
       PVOID            pReserved
);