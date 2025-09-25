typedef struct _BTH_RADIO_INFO {
  ULONGLONG lmpSupportedFeatures;
  USHORT    mfg;
  USHORT    lmpSubversion;
  UCHAR     lmpVersion;
} BTH_RADIO_INFO, *PBTH_RADIO_INFO;