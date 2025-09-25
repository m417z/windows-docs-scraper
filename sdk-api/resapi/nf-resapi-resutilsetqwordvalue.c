DWORD ResUtilSetQwordValue(
  [in]                HKEY       hkeyClusterKey,
  [in]                LPCWSTR    pszValueName,
  [in]                ULONGLONG  qwNewValue,
  [in, out, optional] PULONGLONG pqwOutValue
);