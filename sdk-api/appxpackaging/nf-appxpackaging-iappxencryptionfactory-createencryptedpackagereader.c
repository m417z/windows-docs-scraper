HRESULT CreateEncryptedPackageReader(
  [in]          IStream             *inputStream,
  [in]          const APPX_KEY_INFO *keyInfo,
  [out, retval] IAppxPackageReader  **packageReader
);