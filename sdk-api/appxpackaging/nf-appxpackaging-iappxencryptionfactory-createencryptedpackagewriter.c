HRESULT CreateEncryptedPackageWriter(
  [in]          IStream                               *outputStream,
  [in]          IStream                               *manifestStream,
  [in]          const APPX_ENCRYPTED_PACKAGE_SETTINGS *settings,
  [in]          const APPX_KEY_INFO                   *keyInfo,
                const APPX_ENCRYPTED_EXEMPTIONS       *exemptedFiles,
  [out, retval] IAppxEncryptedPackageWriter           **packageWriter
);