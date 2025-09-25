typedef struct _DHCP_OPTION {
  DHCP_OPTION_ID   OptionID;
  LPWSTR           OptionName;
  LPWSTR           OptionComment;
  DHCP_OPTION_DATA DefaultValue;
  DHCP_OPTION_TYPE OptionType;
} DHCP_OPTION, *LPDHCP_OPTION;