typedef struct _WWAN_UMTS_SERVING_CELL_INFO {
  ULONG ProviderIdOffset;
  ULONG ProviderIdSize;
  ULONG LocationAreaCode;
  ULONG CellId;
  ULONG FrequencyInfoUL;
  ULONG FrequencyInfoDL;
  ULONG FrequencyInfoNT;
  ULONG UARFCN;
  ULONG PrimaryScramblingCode;
  ULONG RSCP;
  ULONG ECNO;
  ULONG PathLoss;
  BYTE  Data[ANYSIZE_ARRAY];
} WWAN_UMTS_SERVING_CELL_INFO, *PWWAN_UMTS_SERVING_CELL_INFO;