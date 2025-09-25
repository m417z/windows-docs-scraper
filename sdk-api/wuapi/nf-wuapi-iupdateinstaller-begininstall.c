HRESULT BeginInstall(
  [in]  IUnknown         *onProgressChanged,
  [in]  IUnknown         *onCompleted,
  [in]  VARIANT          state,
  [out] IInstallationJob **retval
);