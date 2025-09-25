typedef struct _SCSI_ADDR {
  UCHAR PortNumber;
  UCHAR ScsiPathId;
  UCHAR TargetId;
  UCHAR Lun;
} SCSI_ADDR, *PSCSI_ADDR;