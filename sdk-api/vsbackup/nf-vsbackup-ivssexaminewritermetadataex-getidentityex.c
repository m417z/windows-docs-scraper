HRESULT GetIdentityEx(
  [out] VSS_ID          *pidInstance,
  [out] VSS_ID          *pidWriter,
  [out] BSTR            *pbstrWriterName,
  [out] BSTR            *pbstrInstanceName,
  [out] VSS_USAGE_TYPE  *pUsage,
  [out] VSS_SOURCE_TYPE *pSource
);