typedef struct _NVME_TELEMETRY_HOST_INITIATED_LOG {
  UCHAR  LogIdentifier;
  UCHAR  Reserved0[4];
  UCHAR  OrganizationID[3];
  USHORT Area1LastBlock;
  USHORT Area2LastBlock;
  USHORT Area3LastBlock;
  UCHAR  Reserved1[2];
  ULONG  Area4LastBlock;
  UCHAR  Reserved2[361];
  UCHAR  HostInitiatedDataGenerationNumber;
  UCHAR  ControllerInitiatedDataAvailable;
  UCHAR  ControllerInitiatedDataGenerationNumber;
  UCHAR  ReasonIdentifier[128];
} NVME_TELEMETRY_HOST_INITIATED_LOG, *PNVME_TELEMETRY_HOST_INITIATED_LOG;