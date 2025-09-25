HRESULT CreatePackageReader2(
  [in]          IStream            *inputStream,
  [in,optional] LPCWSTR            expectedDigest,
  [out]         IAppxPackageReader **packageReader
);