DWORD DhcpEnumClasses(
  [in]      LPWSTR                  ServerIpAddress,
  [in]      DWORD                   ReservedMustBeZero,
  [in, out] DHCP_RESUME_HANDLE      *ResumeHandle,
  [in]      DWORD                   PreferredMaximum,
  [out]     LPDHCP_CLASS_INFO_ARRAY *ClassInfoArray,
  [out]     DWORD                   *nRead,
  [out]     DWORD                   *nTotal
);