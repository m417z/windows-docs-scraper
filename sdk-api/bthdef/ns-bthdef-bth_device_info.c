typedef struct _BTH_DEVICE_INFO {
  ULONG    flags;
  BTH_ADDR address;
  BTH_COD  classOfDevice;
  CHAR     name[BTH_MAX_NAME_SIZE];
} BTH_DEVICE_INFO, *PBTH_DEVICE_INFO;