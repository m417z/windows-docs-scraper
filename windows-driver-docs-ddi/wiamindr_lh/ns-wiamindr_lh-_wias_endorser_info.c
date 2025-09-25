typedef struct _WIAS_ENDORSER_INFO {
  ULONG               ulPageCount;
  ULONG               ulNumEndorserValues;
  WIAS_ENDORSER_VALUE *pEndorserValues;
} WIAS_ENDORSER_INFO, *PWIAS_ENDORSER_INFO;