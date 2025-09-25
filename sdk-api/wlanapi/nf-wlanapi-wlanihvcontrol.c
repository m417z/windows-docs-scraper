DWORD WlanIhvControl(
  [in]                HANDLE                hClientHandle,
  [in]                const GUID            *pInterfaceGuid,
  [in]                WLAN_IHV_CONTROL_TYPE Type,
  [in]                DWORD                 dwInBufferSize,
  [in]                PVOID                 pInBuffer,
  [in]                DWORD                 dwOutBufferSize,
  [in, out, optional] PVOID                 pOutBuffer,
  [out]               PDWORD                pdwBytesReturned
);