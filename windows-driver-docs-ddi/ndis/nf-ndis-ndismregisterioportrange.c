NDIS_STATUS NdisMRegisterIoPortRange(
  [out] PVOID       *PortOffset,
  [in]  NDIS_HANDLE MiniportAdapterHandle,
  [in]  UINT        InitialPort,
  [in]  UINT        NumberOfPorts
);