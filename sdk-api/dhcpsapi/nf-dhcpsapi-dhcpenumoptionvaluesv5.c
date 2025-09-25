DWORD DhcpEnumOptionValuesV5(
  [in]      LPWSTR                    ServerIpAddress,
  [in]      DWORD                     Flags,
  [in]      LPWSTR                    ClassName,
  [in]      LPWSTR                    VendorName,
  [in]      LPDHCP_OPTION_SCOPE_INFO  ScopeInfo,
  [in, out] DHCP_RESUME_HANDLE        *ResumeHandle,
  [in]      DWORD                     PreferredMaximum,
  [out]     LPDHCP_OPTION_VALUE_ARRAY *OptionValues,
  [out]     DWORD                     *OptionsRead,
  [out]     DWORD                     *OptionsTotal
);