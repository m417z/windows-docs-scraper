typedef struct _USB_DEVICE_CAPABILITY_FIRMWARE_STATUS_DESCRIPTOR {
  UCHAR bLength;
  UCHAR bDescriptorType;
  UCHAR bDevCapabilityType;
  UCHAR bcdDescriptorVersion;
  union {
    ULONG AsUlong;
    struct {
      ULONG GetFirmwareImageHashSupport : 1;
      ULONG DisallowFirmwareUpdateSupport : 1;
      ULONG Reserved : 30;
    };
  } bmAttributes;
} USB_DEVICE_CAPABILITY_FIRMWARE_STATUS_DESCRIPTOR, *PUSB_DEVICE_CAPABILITY_FIRMWARE_STATUS_DESCRIPTOR;