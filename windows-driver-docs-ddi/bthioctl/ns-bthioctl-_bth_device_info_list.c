typedef struct _BTH_DEVICE_INFO_LIST {
  ULONG           numOfDevices;
  BTH_DEVICE_INFO deviceList[1];
} BTH_DEVICE_INFO_LIST, *PBTH_DEVICE_INFO_LIST;