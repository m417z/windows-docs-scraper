FN_HANDLE_CMD FnHandleCmd;

DWORD FnHandleCmd(
  [in]  LPCWSTR pwszMachine,
  [in]  LPWSTR *ppwcArguments,
  [in]  DWORD dwCurrentIndex,
  [in]  DWORD dwArgCount,
  [in]  DWORD dwFlags,
  [in]  LPCVOID pvData,
  [out] BOOL *pbDone
)
{...}