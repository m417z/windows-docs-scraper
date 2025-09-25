PWLX_CHANGE_PASSWORD_NOTIFY_EX PwlxChangePasswordNotifyEx;

int PwlxChangePasswordNotifyEx(
  [in] HANDLE hWlx,
  [in] PWLX_MPR_NOTIFY_INFO pMprInfo,
  [in] DWORD dwChangeInfo,
  [in] PWSTR ProviderName,
  [in] PVOID Reserved
)
{...}