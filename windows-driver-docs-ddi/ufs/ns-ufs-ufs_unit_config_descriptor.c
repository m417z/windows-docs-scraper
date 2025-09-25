typedef struct {
  UCHAR bLUEnable;
  UCHAR bBootLunID;
  UCHAR bLUWriteProtect;
  UCHAR bMemoryType;
  UCHAR dNumAllocUnits[4];
  UCHAR bDataReliability;
  UCHAR bLogicalBlockSize;
  UCHAR bProvisioningType;
  UCHAR wContextCapabilities[2];
  UCHAR Reserved[3];
} UFS_UNIT_CONFIG_DESCRIPTOR, *PUFS_UNIT_CONFIG_DESCRIPTOR;