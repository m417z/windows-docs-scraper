typedef struct _DOT11_ADAPTER {
  GUID                         gAdapterId;
  LPWSTR                       pszDescription;
  DOT11_CURRENT_OPERATION_MODE Dot11CurrentOpMode;
} DOT11_ADAPTER, *PDOT11_ADAPTER;