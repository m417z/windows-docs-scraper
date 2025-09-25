typedef struct _IO_SCSI_CAPABILITIES {
  ULONG   Length;
  ULONG   MaximumTransferLength;
  ULONG   MaximumPhysicalPages;
  ULONG   SupportedAsynchronousEvents;
  ULONG   AlignmentMask;
  BOOLEAN TaggedQueuing;
  BOOLEAN AdapterScansDown;
  BOOLEAN AdapterUsesPio;
} IO_SCSI_CAPABILITIES, *PIO_SCSI_CAPABILITIES;