HRESULT CreateEncryptedBundleReader(
  [in]          IStream             *inputStream,
  [in]          const APPX_KEY_INFO *keyInfo,
  [out, retval] IAppxBundleReader   **bundleReader
);