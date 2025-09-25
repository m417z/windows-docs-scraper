BOOL AllJoynSendToBus(
  [in]            HANDLE     connectedBusHandle,
  [in]            const VOID *buffer,
  [in]            DWORD      bytesToWrite,
  [out, optional] PDWORD     bytesTransferred,
  [in, out]       PVOID      reserved
);