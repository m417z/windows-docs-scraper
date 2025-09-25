typedef struct _IRB_REQ_SEND_PHY_PACKET {
  ULONG          Flags;
  ULONG          GenerationCount;
  ULARGE_INTEGER PhyPacket;
} IRB_REQ_SEND_PHY_PACKET;