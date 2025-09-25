CMAPI CONFIGRET CM_Set_Device_Interface_Property_ExW(
  [in]           LPCWSTR          pszDeviceInterface,
  [in]           const DEVPROPKEY *PropertyKey,
  [in]           DEVPROPTYPE      PropertyType,
  [in]           const PBYTE      PropertyBuffer,
  [in]           ULONG            PropertyBufferSize,
  [in]           ULONG            ulFlags,
  [in, optional] HMACHINE         hMachine
);