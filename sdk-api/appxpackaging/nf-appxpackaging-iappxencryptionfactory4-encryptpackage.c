HRESULT EncryptPackage(
  [in] IStream                                *inputStream,
  [in] IStream                                *outputStream,
  [in] const APPX_ENCRYPTED_PACKAGE_SETTINGS2 *settings,
  [in] const APPX_KEY_INFO                    *keyInfo,
  [in] const APPX_ENCRYPTED_EXEMPTIONS        *exemptedFiles,
  [in] UINT64                                 memoryLimit
);