typedef struct _WIFI_BAND_CAPABILITIES {
  ULONG          Size;
  ULONG          NumBands;
  WIFI_BAND_INFO *BandInfoList;
} WIFI_BAND_CAPABILITIES;