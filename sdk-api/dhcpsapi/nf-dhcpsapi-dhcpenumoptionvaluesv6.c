DWORD DHCP_API_FUNCTION DhcpEnumOptionValuesV6(
  [in]      DHCP_CONST WCHAR          *ServerIpAddress,
  [in]      DWORD                     Flags,
  [in]      LPWSTR                    ClassName,
  [in]      LPWSTR                    VendorName,
  [in]      LPDHCP_OPTION_SCOPE_INFO6 ScopeInfo,
  [in, out] DHCP_RESUME_HANDLE        *ResumeHandle,
  [in]      DWORD                     PreferredMaximum,
  [out]     LPDHCP_OPTION_VALUE_ARRAY *OptionValues,
  [out]     DWORD                     *OptionsRead,
  [out]     DWORD                     *OptionsTotal
);