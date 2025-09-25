DWORD WlanGetSecuritySettings(
  [in]            HANDLE                  hClientHandle,
  [in]            WLAN_SECURABLE_OBJECT   SecurableObject,
  [out, optional] PWLAN_OPCODE_VALUE_TYPE pValueType,
  [out]           LPWSTR                  *pstrCurrentSDDL,
  [out]           PDWORD                  pdwGrantedAccess
);