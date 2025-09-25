CMAPI CONFIGRET CM_Get_DevNode_Property_ExW(
  [in]           DEVINST          dnDevInst,
  [in]           const DEVPROPKEY *PropertyKey,
  [out]          DEVPROPTYPE      *PropertyType,
  [out]          PBYTE            PropertyBuffer,
  [in, out]      PULONG           PropertyBufferSize,
  [in]           ULONG            ulFlags,
  [in, optional] HMACHINE         hMachine
);