typedef struct _BTH_LOCAL_RADIO_INFO {
  BTH_DEVICE_INFO localInfo;
  ULONG           flags;
  USHORT          hciRevision;
  UCHAR           hciVersion;
  BTH_RADIO_INFO  radioInfo;
} BTH_LOCAL_RADIO_INFO, *PBTH_LOCAL_RADIO_INFO;