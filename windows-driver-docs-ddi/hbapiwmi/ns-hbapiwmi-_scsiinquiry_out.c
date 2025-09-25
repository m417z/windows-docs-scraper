typedef struct _ScsiInquiry_OUT {
  ULONG HBAStatus;
  ULONG ResponseBufferSize;
  ULONG SenseBufferSize;
  UCHAR ScsiStatus;
  UCHAR ResponseBuffer[1];
} ScsiInquiry_OUT, *PScsiInquiry_OUT;