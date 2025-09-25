CMAPI CONFIGRET CM_Set_DevNode_Property_ExW(
  [in]           DEVINST          dnDevInst,
  [in]           const DEVPROPKEY *PropertyKey,
  [in]           DEVPROPTYPE      PropertyType,
  [in]           const PBYTE      PropertyBuffer,
  [in]           ULONG            PropertyBufferSize,
  [in]           ULONG            ulFlags,
  [in, optional] HMACHINE         hMachine
);