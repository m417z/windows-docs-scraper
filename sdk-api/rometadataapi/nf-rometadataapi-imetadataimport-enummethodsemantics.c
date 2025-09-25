HRESULT EnumMethodSemantics(
  [in, out] HCORENUM    *phEnum,
  [in]      mdMethodDef tkMethodDef,
  [out]     mdToken []  rgEventProp,
  [in]      ULONG       cMax,
  [out]     ULONG       *pcEventProp
);