typedef struct _PPP_EAP_PACKET {
  BYTE Code;
  BYTE Id;
  BYTE Length[2];
  BYTE Data[1];
} PPP_EAP_PACKET, *PPPP_EAP_PACKET;