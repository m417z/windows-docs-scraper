typedef struct _EAP_INTERACTIVE_UI_DATA {
  DWORD                        dwVersion;
  DWORD                        dwSize;
  EAP_INTERACTIVE_UI_DATA_TYPE dwDataType;
  DWORD                        cbUiData;
#if ...
  EAP_UI_DATA_FORMAT           pbUiData;
#else
  EAP_UI_DATA_FORMAT           pbUiData;
#endif
} EAP_INTERACTIVE_UI_DATA;