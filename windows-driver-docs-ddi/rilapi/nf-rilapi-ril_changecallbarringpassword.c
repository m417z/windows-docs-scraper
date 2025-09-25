HRESULT RIL_ChangeCallBarringPassword(
  HRIL                           hRil,
  LPVOID                         lpContext,
  DWORD                          dwExecutor,
  RILCALLBARRINGSTATUSPARAMSTYPE dwType,
  LPCSTR                         lpwszOldPassword,
  LPCSTR                         lpwszNewPassword,
  LPCSTR                         lpszConfirmPassword
);