typedef struct _HBAScsiID {
  ULONG  ScsiBusNumber;
  ULONG  ScsiTargetNumber;
  ULONG  ScsiOSLun;
  USHORT OSDeviceName[257];
} HBAScsiID, *PHBAScsiID;