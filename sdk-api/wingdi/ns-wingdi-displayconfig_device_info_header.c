typedef struct DISPLAYCONFIG_DEVICE_INFO_HEADER {
  DISPLAYCONFIG_DEVICE_INFO_TYPE type;
  UINT32                         size;
  LUID                           adapterId;
  UINT32                         id;
} DISPLAYCONFIG_DEVICE_INFO_HEADER;