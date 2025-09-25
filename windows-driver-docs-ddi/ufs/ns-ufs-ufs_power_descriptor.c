typedef struct {
  UCHAR bLength;
  UCHAR bDescriptorIDN;
  UCHAR wActiveICCLevelsVCC[32];
  UCHAR wActiveICCLevelsVCCQ[32];
  UCHAR wActiveICCLevelsVCCQ2[32];
} UFS_POWER_DESCRIPTOR, *PUFS_POWER_DESCRIPTOR;