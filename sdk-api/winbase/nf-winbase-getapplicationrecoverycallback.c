HRESULT GetApplicationRecoveryCallback(
  [in]  HANDLE                        hProcess,
  [out] APPLICATION_RECOVERY_CALLBACK *pRecoveryCallback,
  [out] PVOID                         *ppvParameter,
  [out] PDWORD                        pdwPingInterval,
  [out] PDWORD                        pdwFlags
);