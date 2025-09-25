typedef struct _GET_MEDIA_TYPES {
  DWORD             DeviceType;
  DWORD             MediaInfoCount;
  DEVICE_MEDIA_INFO MediaInfo[1];
} GET_MEDIA_TYPES, *PGET_MEDIA_TYPES;