typedef struct _ScsiReportLuns_OUT {
  ULONG HBAStatus;
  ULONG ResponseBufferSize;
  ULONG SenseBufferSize;
  UCHAR ScsiStatus;
  UCHAR ResponseBuffer[1];
} ScsiReportLuns_OUT, *PScsiReportLuns_OUT;