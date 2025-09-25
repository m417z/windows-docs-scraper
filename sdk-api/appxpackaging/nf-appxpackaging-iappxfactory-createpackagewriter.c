HRESULT CreatePackageWriter(
  [in]          IStream               *outputStream,
  [in]          APPX_PACKAGE_SETTINGS *settings,
  [out, retval] IAppxPackageWriter    **packageWriter
);