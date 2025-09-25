typedef struct {
  UCHAR bLength;
  UCHAR bDescriptorIDN;
  UCHAR bPreEOLInfo;
  UCHAR bDeviceLifeTimeEstA;
  UCHAR bDeviceLifeTimeEstB;
  UCHAR VendorPropInfo[32];
  ULONG dRefreshTotalCount;
  ULONG dRefreshProgress;
} UFS_DEVICE_HEALTH_DESCRIPTOR, *PUFS_DEVICE_HEALTH_DESCRIPTOR;