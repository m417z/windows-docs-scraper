typedef struct _WWAN_PCO_VALUE {
  ULONG         Size;
  WWAN_PCO_TYPE Type;
  BYTE          PcoData[WWAN_PCO_OCT_BUF_LEN];
} WWAN_PCO_VALUE, *PWWAN_PCO_VALUE;