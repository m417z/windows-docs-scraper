typedef struct tagRID_DEVICE_INFO_HID {
  DWORD  dwVendorId;
  DWORD  dwProductId;
  DWORD  dwVersionNumber;
  USHORT usUsagePage;
  USHORT usUsage;
} RID_DEVICE_INFO_HID, *PRID_DEVICE_INFO_HID;