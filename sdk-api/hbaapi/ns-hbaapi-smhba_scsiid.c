typedef struct SMHBA_ScsiId {
  char       OSDeviceName[256];
  HBA_UINT32 ScsiBusNumber;
  HBA_UINT32 ScsiTargetNumber;
  HBA_UINT32 ScsiOSLun;
} SMHBA_SCSIID, *PSMHBA_SCSIID;