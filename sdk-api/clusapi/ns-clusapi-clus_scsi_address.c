typedef struct CLUS_SCSI_ADDRESS {
  union {
    struct {
      UCHAR PortNumber;
      UCHAR PathId;
      UCHAR TargetId;
      UCHAR Lun;
    } DUMMYSTRUCTNAME;
    DWORD dw;
  } DUMMYUNIONNAME;
} CLUS_SCSI_ADDRESS, *PCLUS_SCSI_ADDRESS;