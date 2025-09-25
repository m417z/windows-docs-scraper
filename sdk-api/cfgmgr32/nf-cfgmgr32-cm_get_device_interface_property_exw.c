CMAPI CONFIGRET CM_Get_Device_Interface_Property_ExW(
  [in]           LPCWSTR          pszDeviceInterface,
  [in]           const DEVPROPKEY *PropertyKey,
  [out]          DEVPROPTYPE      *PropertyType,
  [out]          PBYTE            PropertyBuffer,
  [in, out]      PULONG           PropertyBufferSize,
  [in]           ULONG            ulFlags,
  [in, optional] HMACHINE         hMachine
);