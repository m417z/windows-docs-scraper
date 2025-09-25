typedef struct _HID_DEVICE_EXTENSION {
  PDEVICE_OBJECT PhysicalDeviceObject;
  PDEVICE_OBJECT NextDeviceObject;
  PVOID          MiniDeviceExtension;
} HID_DEVICE_EXTENSION, *PHID_DEVICE_EXTENSION;