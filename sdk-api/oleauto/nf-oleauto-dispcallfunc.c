HRESULT DispCallFunc(
  void       *pvInstance,
  ULONG_PTR  oVft,
  CALLCONV   cc,
  VARTYPE    vtReturn,
  UINT       cActuals,
  VARTYPE    *prgvt,
  VARIANTARG **prgpvarg,
  VARIANT    *pvargResult
);