typedef struct {
  UCHAR                      bLength;
  UCHAR                      bDescriptorIDN;
  UCHAR                      bConfDescContinue;
  UCHAR                      bBootEnable;
  UCHAR                      bDescrAccessEn;
  UCHAR                      bInitPowerMode;
  UCHAR                      bHighPriorityLUN;
  UCHAR                      bSecureRemovalType;
  UCHAR                      bInitActiveICCLevel;
  UCHAR                      wPeriodicRTCUpdate[2];
  UCHAR                      Reserved2[1];
  UCHAR                      bRPMBRegionEnable;
  UCHAR                      bRPMBRegion1Size;
  UCHAR                      bRPMBRegion2Size;
  UCHAR                      bRPMBRegion3Size;
  UFS_UNIT_CONFIG_DESCRIPTOR UnitConfig[UFS_MAX_NUM_LU];
} UFS_CONFIG_DESCRIPTOR, *PUFS_CONFIG_DESCRIPTOR;