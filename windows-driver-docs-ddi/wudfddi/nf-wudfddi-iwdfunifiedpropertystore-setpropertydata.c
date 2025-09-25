HRESULT SetPropertyData(
  [in]           const DEVPROPKEY *PropertyKey,
  [in]           LCID             Lcid,
  [in]           ULONG            Flags,
  [in]           DEVPROPTYPE      PropertyType,
  [in]           ULONG            PropertyDataSize,
  [in, optional] PVOID            PropertyData
);