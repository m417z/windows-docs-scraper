typedef struct _AVCCONNECTINFO {
  GUID           DeviceID;
  UCHAR          SubunitAddress[AVCCONNECTINFO_MAX_SUBUNITADDR_LEN];
  ULONG          SubunitPlugNumber;
  KSPIN_DATAFLOW DataFlow;
  HANDLE         hPlug;
  ULONG          UnitPlugNumber;
} AVCCONNECTINFO, *PAVCCONNECTINFO;