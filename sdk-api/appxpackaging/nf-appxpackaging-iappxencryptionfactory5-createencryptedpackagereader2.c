HRESULT CreateEncryptedPackageReader2(
  IStream             *inputStream,
  const APPX_KEY_INFO *keyInfo,
  LPCWSTR             expectedDigest,
  IAppxPackageReader  **packageReader
);