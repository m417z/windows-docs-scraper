DWORD WlanSetAutoConfigParameter(
  [in] HANDLE               hClientHandle,
  [in] WLAN_AUTOCONF_OPCODE OpCode,
  [in] DWORD                dwDataSize,
  [in] const PVOID          pData,
       PVOID                pReserved
);