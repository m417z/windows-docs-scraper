HRESULT RegisterForPackageStateChanges(
  [in]  LPCWSTR                                  packageFullName,
  [in]  IPackageExecutionStateChangeNotification *pPackageExecutionStateChangeNotification,
  [out] DWORD                                    *pdwCookie
);