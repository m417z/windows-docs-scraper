typedef struct _HUB_DEVICE_CONFIG_INFO_V1 {
  ULONG                       Version;
  ULONG                       Length;
  USB_HUB_CAP_FLAGS           HubFlags;
  USB_ID_STRING               HardwareIds;
  USB_ID_STRING               CompatibleIds;
  USB_ID_STRING               DeviceDescription;
  ULONG                       Reserved[19];
  USB_HUB_DEVICE_UXD_SETTINGS UxdSettings;
} HUB_DEVICE_CONFIG_INFO, *PHUB_DEVICE_CONFIG_INFO;