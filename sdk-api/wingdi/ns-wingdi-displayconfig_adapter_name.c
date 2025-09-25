typedef struct DISPLAYCONFIG_ADAPTER_NAME {
  DISPLAYCONFIG_DEVICE_INFO_HEADER header;
  WCHAR                            adapterDevicePath[128];
} DISPLAYCONFIG_ADAPTER_NAME;