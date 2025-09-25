VOID NdisMDeregisterIoPortRange(
  [in] NDIS_HANDLE MiniportAdapterHandle,
  [in] UINT        InitialPort,
  [in] UINT        NumberOfPorts,
  [in] PVOID       PortOffset
);