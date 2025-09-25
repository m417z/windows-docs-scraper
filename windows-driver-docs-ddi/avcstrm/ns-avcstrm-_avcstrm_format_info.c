typedef struct _AVCSTRM_FORMAT_INFO {
  ULONG          SizeOfThisBlock;
  AVCSTRM_FORMAT AVCStrmFormat;
  CIP_HDR1       cipHdr1;
  CIP_HDR2_SYT   cipHdr2;
  ULONG          SrcPacketsPerFrame;
  ULONG          FrameSize;
  ULONG          NumOfRcvBuffers;
  ULONG          NumOfXmtBuffers;
  DWORD          OptionFlags;
  ULONG          AvgTimePerFrame;
  ULONG          BlockPeriod;
  ULONG          Reserved[4];
} AVCSTRM_FORMAT_INFO, *PAVCSTRM_FORMAT_INFO;