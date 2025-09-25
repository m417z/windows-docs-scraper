HRESULT CreatePropertyGroup(
  [in]      BSTR                 Name,
  [in, out] LONG                 *dwIsoMode,
  [in, out] LONG                 *dwRelMode,
  [out]     VARIANT_BOOL         *fExists,
  [out]     ISharedPropertyGroup **ppGroup
);