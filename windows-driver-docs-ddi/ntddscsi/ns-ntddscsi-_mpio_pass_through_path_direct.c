typedef struct _MPIO_PASS_THROUGH_PATH_DIRECT {
  SCSI_PASS_THROUGH_DIRECT PassThrough;
  ULONG                    Version;
  USHORT                   Length;
  UCHAR                    Flags;
  UCHAR                    PortNumber;
  ULONGLONG                MpioPathId;
} MPIO_PASS_THROUGH_PATH_DIRECT, *PMPIO_PASS_THROUGH_PATH_DIRECT;