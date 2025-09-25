typedef struct _WSMAN_OPERATION_INFO {
  WSMAN_FRAGMENT     fragment;
  WSMAN_FILTER       filter;
  WSMAN_SELECTOR_SET selectorSet;
  WSMAN_OPTION_SET   optionSet;
  void               *reserved;
  DWORD              version;
} WSMAN_OPERATION_INFO;