typedef struct _DHCP_OPTION_LIST {
  DWORD             NumOptions;
  DHCP_OPTION_VALUE *Options;
} DHCP_OPTION_LIST, *LPDHCP_OPTION_LIST;