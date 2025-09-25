HRESULT CreateBundleReader2(
  [in]          IStream           *inputStream,
  [in,optional] LPCWSTR           expectedDigest,
  [out]         IAppxBundleReader **bundleReader
);