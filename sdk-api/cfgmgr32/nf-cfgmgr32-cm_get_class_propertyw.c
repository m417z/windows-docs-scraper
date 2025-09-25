CMAPI CONFIGRET CM_Get_Class_PropertyW(
  [in]      LPCGUID          ClassGUID,
  [in]      const DEVPROPKEY *PropertyKey,
  [out]     DEVPROPTYPE      *PropertyType,
  [out]     PBYTE            PropertyBuffer,
  [in, out] PULONG           PropertyBufferSize,
  [in]      ULONG            ulFlags
);