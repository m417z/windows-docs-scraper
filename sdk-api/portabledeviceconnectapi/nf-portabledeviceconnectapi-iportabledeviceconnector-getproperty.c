HRESULT GetProperty(
  [in]  const DEVPROPKEY *pPropertyKey,
  [out] DEVPROPTYPE      *pPropertyType,
  [out] BYTE             **ppData,
  [out] UINT32           *pcbData
);