typedef struct _DHCP_ALL_OPTIONS {
  DWORD                   Flags;
  LPDHCP_OPTION_ARRAY     NonVendorOptions;
  DWORD                   NumVendorOptions;
  struct {
    DHCP_OPTION Option;
    LPWSTR      VendorName;
    LPWSTR      ClassName;
  };
  __unnamed_struct_00b7_3 *VendorOptions;
} DHCP_ALL_OPTIONS, *LPDHCP_ALL_OPTIONS;