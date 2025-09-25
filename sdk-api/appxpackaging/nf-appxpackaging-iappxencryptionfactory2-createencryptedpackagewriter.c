HRESULT CreateEncryptedPackageWriter(
  [in]          IStream                               *outputStream,
  [in]          IStream                               *manifestStream,
  [in]          IStream                               *contentGroupMapStream,
  [in]          const APPX_ENCRYPTED_PACKAGE_SETTINGS *settings,
  [in]          const APPX_KEY_INFO                   *keyInfo,
  [in]          const APPX_ENCRYPTED_EXEMPTIONS       *exemptedFiles,
  [out, retval] IAppxEncryptedPackageWriter           **packageWriter
);