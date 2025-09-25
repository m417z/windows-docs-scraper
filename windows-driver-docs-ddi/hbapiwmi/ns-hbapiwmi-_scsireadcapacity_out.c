typedef struct _ScsiReadCapacity_OUT {
  ULONG HBAStatus;
  ULONG ResponseBufferSize;
  ULONG SenseBufferSize;
  UCHAR ScsiStatus;
  UCHAR ResponseBuffer[1];
} ScsiReadCapacity_OUT, *PScsiReadCapacity_OUT;