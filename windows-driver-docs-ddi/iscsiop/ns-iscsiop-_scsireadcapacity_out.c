typedef struct _ScsiReadCapacity_OUT {
  ULONG Status;
  ULONG ResponseBufferSize;
  UCHAR ScsiStatus;
  UCHAR SenseBuffer[18];
  UCHAR ResponseBuffer[1];
} ScsiReadCapacity_OUT, *PScsiReadCapacity_OUT;