typedef struct _RM_FEC_INFO {
  USHORT  FECBlockSize;
  USHORT  FECProActivePackets;
  UCHAR   FECGroupSize;
  BOOLEAN fFECOnDemandParityEnabled;
} RM_FEC_INFO;