HRESULT GetIdentity(
  [out] VSS_ID          *pidInstance,
  [out] VSS_ID          *pidWriter,
  [out] BSTR            *pbstrWriterName,
  [out] VSS_USAGE_TYPE  *pUsage,
  [out] VSS_SOURCE_TYPE *pSource
);