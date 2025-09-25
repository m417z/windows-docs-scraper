HRESULT wiauRegGetStrW(
  [in]      HKEY   hkKey,
  [in]      PCWSTR pwszValueName,
  [out]     PWSTR  pwszValue,
  [in, out] WORD   *pdwLength
);