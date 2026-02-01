typedef struct _DHCP_ALL_OPTION_VALUES {
  DWORD                   Flags;
  DWORD                   NumElements;
  struct {
    LPWSTR                    ClassName;
    LPWSTR                    VendorName;
    BOOL                      IsVendor;
    LPDHCP_OPTION_VALUE_ARRAY OptionsArray;
  };
  __unnamed_struct_00b8_4 *Options;
} DHCP_ALL_OPTION_VALUES, *LPDHCP_ALL_OPTION_VALUES;