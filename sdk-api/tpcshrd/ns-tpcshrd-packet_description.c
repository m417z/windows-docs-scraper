typedef struct _PACKET_DESCRIPTION {
  ULONG           cbPacketSize;
  ULONG           cPacketProperties;
  PACKET_PROPERTY *pPacketProperties;
  ULONG           cButtons;
  GUID            *pguidButtons;
} PACKET_DESCRIPTION, *PPACKET_DESCRIPTION;