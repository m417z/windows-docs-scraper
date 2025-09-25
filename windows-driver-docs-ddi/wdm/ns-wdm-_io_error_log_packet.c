typedef struct _IO_ERROR_LOG_PACKET {
  UCHAR         MajorFunctionCode;
  UCHAR         RetryCount;
  USHORT        DumpDataSize;
  USHORT        NumberOfStrings;
  USHORT        StringOffset;
  USHORT        EventCategory;
  NTSTATUS      ErrorCode;
  ULONG         UniqueErrorValue;
  NTSTATUS      FinalStatus;
  ULONG         SequenceNumber;
  ULONG         IoControlCode;
  LARGE_INTEGER DeviceOffset;
  ULONG         DumpData[1];
} IO_ERROR_LOG_PACKET, *PIO_ERROR_LOG_PACKET;