SECURITY_STATUS NCryptQueryProtectionDescriptorName(
  [in]      LPCWSTR pwszName,
  [out]     LPWSTR  pwszDescriptorString,
  [in, out] SIZE_T  *pcDescriptorString,
            DWORD   dwFlags
);