HRESULT EncryptBundle(
  [in] IStream                               *inputStream,
  [in] IStream                               *outputStream,
  [in] const APPX_ENCRYPTED_PACKAGE_SETTINGS *settings,
  [in] const APPX_KEY_INFO                   *keyInfo,
       const APPX_ENCRYPTED_EXEMPTIONS       *exemptedFiles
);