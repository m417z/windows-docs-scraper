typedef struct _WINBIO_GET_INDICATOR {
  DWORD                   PayloadSize;
  HRESULT                 WinBioHresult;
  WINBIO_INDICATOR_STATUS IndicatorStatus;
} WINBIO_GET_INDICATOR, *PWINBIO_GET_INDICATOR;