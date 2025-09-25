HRESULT GetFeaturePage(
  [in]  IMAPI_FEATURE_PAGE_TYPE   requestedFeature,
  [in]  BOOLEAN                   currentFeatureOnly,
  [out] BYTE                      **featureData,
  [out] ULONG_IMAPI2_FEATURE_PAGE *byteSize
);