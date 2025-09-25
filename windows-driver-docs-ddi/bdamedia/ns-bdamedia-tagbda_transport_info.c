typedef struct tagBDA_TRANSPORT_INFO {
  ULONG          ulcbPhyiscalPacket;
  ULONG          ulcbPhyiscalFrame;
  ULONG          ulcbPhyiscalFrameAlignment;
  REFERENCE_TIME AvgTimePerFrame;
} BDA_TRANSPORT_INFO, *PBDA_TRANSPORT_INFO;