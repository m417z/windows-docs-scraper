typedef struct _WWAN_GSM_NMR_INFO {
  ULONG ProviderIdOffset;
  ULONG ProviderIdSize;
  ULONG LocationAreaCode;
  ULONG CellId;
  ULONG ARFCN;
  ULONG BaseStationId;
  ULONG RxLevel;
  BYTE  Data[ANYSIZE_ARRAY];
} WWAN_GSM_NMR_INFO, *PWWAN_GSM_NMR_INFO;