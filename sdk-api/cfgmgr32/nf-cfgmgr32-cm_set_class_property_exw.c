CMAPI CONFIGRET CM_Set_Class_Property_ExW(
  [in]           LPCGUID          ClassGUID,
  [in]           const DEVPROPKEY *PropertyKey,
  [in]           DEVPROPTYPE      PropertyType,
  [in]           const PBYTE      PropertyBuffer,
  [in]           ULONG            PropertyBufferSize,
  [in]           ULONG            ulFlags,
  [in, optional] HMACHINE         hMachine
);