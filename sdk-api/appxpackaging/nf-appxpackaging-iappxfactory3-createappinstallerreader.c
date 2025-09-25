HRESULT CreateAppInstallerReader(
  [in]           IStream                 *inputStream,
  [in, optional] LPCWSTR                 expectedDigest,
  [out]          IAppxAppInstallerReader **appInstallerReader
);