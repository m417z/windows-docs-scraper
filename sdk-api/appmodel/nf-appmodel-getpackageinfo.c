LONG GetPackageInfo(
  [in]            PACKAGE_INFO_REFERENCE packageInfoReference,
  [in]            const UINT32           flags,
  [in, out]       UINT32                 *bufferLength,
  [out, optional] BYTE                   *buffer,
  [out, optional] UINT32                 *count
);