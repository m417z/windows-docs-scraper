DWORD DHCP_API_FUNCTION DhcpEnumClassesV6(
  [in]      LPWSTR                     ServerIpAddress,
  [in]      DWORD                      ReservedMustBeZero,
  [in, out] DHCP_RESUME_HANDLE         *ResumeHandle,
  [in]      DWORD                      PreferredMaximum,
  [out]     LPDHCP_CLASS_INFO_ARRAY_V6 *ClassInfoArray,
  [out]     DWORD                      *nRead,
  [out]     DWORD                      *nTotal
);