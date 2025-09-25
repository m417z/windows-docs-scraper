HRESULT EnumEvents(
  [in, out] HCORENUM   *phEnum,
  [in]      mdTypeDef  tkTypDef,
  [out]     mdEvent [] rgEvents,
  [in]      ULONG      cMax,
  [out]     ULONG      *pcEvents
);