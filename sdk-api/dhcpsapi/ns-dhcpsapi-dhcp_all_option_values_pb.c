typedef struct _DHCP_ALL_OPTION_VALUES_PB {
  DWORD                   Flags;
  DWORD                   NumElements;
  struct {
    LPWSTR                    PolicyName;
    LPWSTR                    VendorName;
    BOOL                      IsVendor;
    LPDHCP_OPTION_VALUE_ARRAY OptionsArray;
  };
  __unnamed_struct_00b7_5 *Options;
} DHCP_ALL_OPTION_VALUES_PB, *LPDHCP_ALL_OPTION_VALUES_PB;