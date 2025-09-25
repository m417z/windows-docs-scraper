typedef struct _IRB_RECEIVE_PHY_PACKETS {
  ULONG                        Flags;
  PBUS_PHY_PACKET_NOTIFICATION PhyPacketRoutine;
  PVOID                        PhyPacketContext;
} IRB_REQ_RECEIVE_PHY_PACKETS;