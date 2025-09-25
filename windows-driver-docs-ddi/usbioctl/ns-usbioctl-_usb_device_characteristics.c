typedef struct _USB_DEVICE_CHARACTERISTICS {
  ULONG Version;
  ULONG Reserved[2];
  ULONG UsbDeviceCharacteristicsFlags;
  ULONG MaximumSendPathDelayInMilliSeconds;
  ULONG MaximumCompletionPathDelayInMilliSeconds;
} USB_DEVICE_CHARACTERISTICS, *PUSB_DEVICE_CHARACTERISTICS;