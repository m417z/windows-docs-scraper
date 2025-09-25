BOOL AllJoynReceiveFromBus(
  [in]            HANDLE connectedBusHandle,
  [out]           PVOID  buffer,
  [in]            DWORD  bytesToRead,
  [out, optional] PDWORD bytesTransferred,
  [in, out]       PVOID  reserved
);