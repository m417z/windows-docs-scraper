typedef struct _ScsiReportLuns_OUT {
  ULONG Status;
  ULONG ResponseBufferSize;
  UCHAR ScsiStatus;
  UCHAR SenseBuffer[18];
  UCHAR ResponseBuffer[1];
} ScsiReportLuns_OUT, *PScsiReportLuns_OUT;