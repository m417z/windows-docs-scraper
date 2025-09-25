typedef struct _DHCP_CLASS_INFO {
  LPWSTR ClassName;
  LPWSTR ClassComment;
  DWORD  ClassDataLength;
  BOOL   IsVendor;
  DWORD  Flags;
  LPBYTE ClassData;
} DHCP_CLASS_INFO, *LPDHCP_CLASS_INFO;