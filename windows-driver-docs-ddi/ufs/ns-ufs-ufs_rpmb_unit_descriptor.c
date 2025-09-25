typedef struct {
  UCHAR bLength;
  UCHAR bDescriptorIDN;
  UCHAR bUnitIndex;
  UCHAR bLUEnable;
  UCHAR bBootLunID;
  UCHAR bLUWriteProtect;
  UCHAR bLUQueueDepth;
  UCHAR bPSASensitive;
  UCHAR bMemoryType;
  UCHAR Reserved;
  UCHAR bLogicalBlockSize;
  UCHAR qLogicalBlockCount[8];
  UCHAR dEraseBlockSize[4];
  UCHAR bProvisioningType;
  UCHAR qPhyMemResourceCount[8];
  UCHAR Reserved2[3];
} UFS_RPMB_UNIT_DESCRIPTOR, *PUFS_RPMB_UNIT_DESCRIPTOR;