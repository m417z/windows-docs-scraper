HRESULT CreateEncryptedBundleReader2(
  [in]          IStream             *inputStream,
  [in]          const APPX_KEY_INFO *keyInfo,
  [in.optional] LPCWSTR             expectedDigest,
  [out]         IAppxBundleReader   **bundleReader
);