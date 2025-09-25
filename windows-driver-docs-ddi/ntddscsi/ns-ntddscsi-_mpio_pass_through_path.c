typedef struct _MPIO_PASS_THROUGH_PATH {
  SCSI_PASS_THROUGH PassThrough;
  ULONG             Version;
  USHORT            Length;
  UCHAR             Flags;
  UCHAR             PortNumber;
  ULONGLONG         MpioPathId;
} MPIO_PASS_THROUGH_PATH, *PMPIO_PASS_THROUGH_PATH;