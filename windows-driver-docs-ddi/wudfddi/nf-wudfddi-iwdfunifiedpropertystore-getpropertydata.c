HRESULT GetPropertyData(
  [in]            const DEVPROPKEY *PropertyKey,
  [in]            LCID             Lcid,
  [in]            ULONG            Flags,
  [in]            ULONG            PropertyDataSize,
  [out, optional] PVOID            PropertyData,
  [out]           ULONG            *PropertyDataRequiredSize,
  [out]           DEVPROPTYPE      *PropertyType
);