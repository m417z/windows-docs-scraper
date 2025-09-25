CMAPI CONFIGRET CM_Get_DevNode_PropertyW(
  [in]      DEVINST          dnDevInst,
  [in]      const DEVPROPKEY *PropertyKey,
  [out]     DEVPROPTYPE      *PropertyType,
  [out]     PBYTE            PropertyBuffer,
  [in, out] PULONG           PropertyBufferSize,
  [in]      ULONG            ulFlags
);