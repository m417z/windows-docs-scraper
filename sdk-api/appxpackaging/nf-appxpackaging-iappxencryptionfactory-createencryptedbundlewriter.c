HRESULT CreateEncryptedBundleWriter(
  [in]          IStream                               *outputStream,
  [in]          UINT64                                bundleVersion,
  [in]          const APPX_ENCRYPTED_PACKAGE_SETTINGS *settings,
  [in]          const APPX_KEY_INFO                   *keyInfo,
                const APPX_ENCRYPTED_EXEMPTIONS       *exemptedFiles,
  [out, retval] IAppxEncryptedBundleWriter            **bundleWriter
);