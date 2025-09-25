HRESULT GetPropValue(
  [in]  const BYTE *pIDString,
  [in]  DWORD      dwIDStringLen,
  [in]  MSAAPROPID idProp,
  [out] VARIANT    *pvarValue,
  [out] BOOL       *pfHasProp
);