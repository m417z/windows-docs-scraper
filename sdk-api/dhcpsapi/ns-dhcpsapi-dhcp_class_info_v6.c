typedef struct _DHCP_CLASS_INFO_V6 {
  LPWSTR ClassName;
  LPWSTR ClassComment;
  DWORD  ClassDataLength;
  BOOL   IsVendor;
  DWORD  EnterpriseNumber;
  DWORD  Flags;
  LPBYTE ClassData;
} DHCP_CLASS_INFO_V6, *LPDHCP_CLASS_INFO_V6;