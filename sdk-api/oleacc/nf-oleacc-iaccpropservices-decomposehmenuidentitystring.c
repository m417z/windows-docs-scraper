HRESULT DecomposeHmenuIdentityString(
  [in]  const BYTE *pIDString,
  [in]  DWORD      dwIDStringLen,
  [out] HMENU      *phmenu,
  [out] DWORD      *pidChild
);