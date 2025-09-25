typedef struct HBA_SBDskCapacity {
  HBA_INT32 SCSIFormatLBA;
  HBA_INT32 SCSIFormatBlkLen;
  HBA_INT32 SBDskNumberOfCylinders;
  HBA_INT32 SBDskTracksPerCylinder;
  HBA_INT32 SBDskMaxUsableTrackLen;
} HBA_SBDSKCAPACITY, *PHBA_SBDSKCAPACITY;