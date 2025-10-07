HRESULT GetPackageInfo3(
  _In_ PACKAGE_INFO_REFERENCE                 packageInfoReference,
  _In_ UINT32                                 flags,
  _In_ PackageInfo3Type                       packageInfoType,
  _Inout_ UINT32                             *bufferLength,
  _Out_writes_bytes_opt_(*bufferLength) void *buffer,
  _Out_opt_ UINT32                           *count
);