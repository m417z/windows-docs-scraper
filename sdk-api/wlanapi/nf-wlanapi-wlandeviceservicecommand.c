DWORD WlanDeviceServiceCommand(
  [in]                HANDLE     hClientHandle,
  [in]                const GUID *pInterfaceGuid,
  [in]                LPGUID     pDeviceServiceGuid,
  [in]                DWORD      dwOpCode,
  [in]                DWORD      dwInBufferSize,
  [in]                PVOID      pInBuffer,
  [in]                DWORD      dwOutBufferSize,
  [in, out, optional] PVOID      pOutBuffer,
  [out]               PDWORD     pdwBytesReturned
);