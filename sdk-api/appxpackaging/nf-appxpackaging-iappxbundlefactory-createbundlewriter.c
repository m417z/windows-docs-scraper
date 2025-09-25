HRESULT CreateBundleWriter(
  [in]          IStream           *outputStream,
  [in]          UINT64            bundleVersion,
  [out, retval] IAppxBundleWriter **bundleWriter
);