typedef struct _WWAN_UMTS_MRL_INFO {
  ULONG ProviderIdOffset;
  ULONG ProviderIdSize;
  ULONG LocationAreaCode;
  ULONG CellId;
  ULONG UARFCN;
  ULONG PrimaryScramblingCode;
  ULONG RSCP;
  ULONG ECNO;
  ULONG PathLoss;
  BYTE  Data[ANYSIZE_ARRAY];
} WWAN_UMTS_MRL_INFO, *PWWAN_UMTS_MRL_INFO;