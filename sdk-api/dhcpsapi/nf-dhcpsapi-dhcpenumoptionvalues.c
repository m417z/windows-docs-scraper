DWORD DHCP_API_FUNCTION DhcpEnumOptionValues(
  [in]      DHCP_CONST WCHAR                  *ServerIpAddress,
  [in]      DHCP_CONST DHCP_OPTION_SCOPE_INFO *ScopeInfo,
  [in, out] DHCP_RESUME_HANDLE                *ResumeHandle,
  [in]      DWORD                             PreferredMaximum,
  [out]     LPDHCP_OPTION_VALUE_ARRAY         *OptionValues,
  [out]     DWORD                             *OptionsRead,
  [out]     DWORD                             *OptionsTotal
);