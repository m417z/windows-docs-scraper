HRESULT UpdateEncryptedPackage(
  [in] IStream                                   *baselineEncryptedPackageStream,
  [in] IStream                                   *deltaPackageStream,
  [in] APPX_PACKAGE_EDITOR_UPDATE_PACKAGE_OPTION updateOption,
  [in] const APPX_ENCRYPTED_PACKAGE_SETTINGS2    *settings,
  [in] const APPX_KEY_INFO                       *keyInfo
);