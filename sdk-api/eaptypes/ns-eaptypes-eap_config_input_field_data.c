typedef struct _EAP_CONFIG_INPUT_FIELD_DATA {
  DWORD                       dwSize;
  EAP_CONFIG_INPUT_FIELD_TYPE Type;
  DWORD                       dwFlagProps;
  LPWSTR                      pwszLabel;
  LPWSTR                      pwszData;
  DWORD                       dwMinDataLength;
  DWORD                       dwMaxDataLength;
} EAP_CONFIG_INPUT_FIELD_DATA, *PEAP_CONFIG_INPUT_FIELD_DATA;