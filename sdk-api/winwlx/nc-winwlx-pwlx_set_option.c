PWLX_SET_OPTION PwlxSetOption;

BOOL PwlxSetOption(
  [in]  HANDLE hWlx,
  [in]  DWORD Option,
  [in]  ULONG_PTR Value,
  [out] ULONG_PTR *OldValue
)
{...}