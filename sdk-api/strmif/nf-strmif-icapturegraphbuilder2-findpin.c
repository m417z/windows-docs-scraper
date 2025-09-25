HRESULT FindPin(
  [in]  IUnknown      *pSource,
  [in]  PIN_DIRECTION pindir,
  [in]  const GUID    *pCategory,
  [in]  const GUID    *pType,
  [in]  BOOL          fUnconnected,
  [in]  int           num,
  [out] IPin          **ppPin
);