typedef struct _PDOSCSI_ADDR {
  UCHAR PortNumber;
  UCHAR ScsiPathId;
  UCHAR TargetId;
  UCHAR Lun;
} PDOSCSI_ADDR, *PPDOSCSI_ADDR;