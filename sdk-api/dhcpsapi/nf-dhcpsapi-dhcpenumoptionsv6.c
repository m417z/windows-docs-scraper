DWORD DHCP_API_FUNCTION DhcpEnumOptionsV6(
  [in]      LPWSTR              ServerIpAddress,
  [in]      DWORD               Flags,
  [in]      LPWSTR              ClassName,
  [in]      LPWSTR              VendorName,
  [in, out] DHCP_RESUME_HANDLE  *ResumeHandle,
  [in]      DWORD               PreferredMaximum,
  [out]     LPDHCP_OPTION_ARRAY *Options,
  [out]     DWORD               *OptionsRead,
  [out]     DWORD               *OptionsTotal
);