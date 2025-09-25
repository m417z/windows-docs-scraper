typedef struct _EAP_CONFIG_INPUT_FIELD_ARRAY {
  DWORD                       dwVersion;
  DWORD                       dwNumberOfFields;
#if ...
  EAP_CONFIG_INPUT_FIELD_DATA *pFields;
#else
  EAP_CONFIG_INPUT_FIELD_DATA *pFields;
#endif
} EAP_CONFIG_INPUT_FIELD_ARRAY, *PEAP_CONFIG_INPUT_FIELD_ARRAY;