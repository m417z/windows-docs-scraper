HRESULT DecomposeHwndIdentityString(
  [in]  const BYTE *pIDString,
  [in]  DWORD      dwIDStringLen,
  [out] HWND       *phwnd,
  [out] DWORD      *pidObject,
  [out] DWORD      *pidChild
);