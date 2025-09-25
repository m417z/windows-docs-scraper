HRESULT RegisterApplicationRecoveryCallback(
  [in]           APPLICATION_RECOVERY_CALLBACK pRecoveyCallback,
  [in, optional] PVOID                         pvParameter,
  [in]           DWORD                         dwPingInterval,
  [in]           DWORD                         dwFlags
);