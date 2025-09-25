typedef struct _WWAN_TDSCDMA_MRL_INFO {
  ULONG ProviderIdOffset;
  ULONG ProviderIdSize;
  ULONG LocationAreaCode;
  ULONG CellId;
  ULONG UARFCN;
  ULONG CellParameterId;
  ULONG TimingAdvance;
  ULONG RSCP;
  ULONG PathLoss;
  BYTE  Data[ANYSIZE_ARRAY];
} WWAN_TDSCDMA_MRL_INFO, *PWWAN_TDSCDMA_MRL_INFO;