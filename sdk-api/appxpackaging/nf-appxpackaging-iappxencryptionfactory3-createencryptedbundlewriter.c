HRESULT CreateEncryptedBundleWriter(
  [in]          IStream                                *outputStream,
  [in]          UINT64                                 bundleVersion,
  [in]          const APPX_ENCRYPTED_PACKAGE_SETTINGS2 *settings,
  [in]          const APPX_KEY_INFO                    *keyInfo,
  [in]          const APPX_ENCRYPTED_EXEMPTIONS        *exemptedFiles,
  [out, retval] IAppxEncryptedBundleWriter             **bundleWriter
);