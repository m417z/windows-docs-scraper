HRESULT CreateMetadata(
  [in]  VSS_ID                          writerId,
  [in]  LPCWSTR                         writerName,
  [in]  VSS_USAGE_TYPE                  usageType,
  [in]  DWORD                           versionMajor,
  [in]  DWORD                           versionMinor,
  [in]  DWORD                           reserved,
  [out] IVssCreateExpressWriterMetadata **ppMetadata
);