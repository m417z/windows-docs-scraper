typedef struct _SELF_ID_MORE {
  ULONG SID_Phys_ID : 6;
  ULONG SID_Packet_ID : 2;
  ULONG SID_PortA : 2;
  ULONG SID_Reserved2 : 2;
  ULONG SID_Sequence : 3;
  ULONG SID_One : 1;
  ULONG SID_PortE : 2;
  ULONG SID_PortD : 2;
  ULONG SID_PortC : 2;
  ULONG SID_PortB : 2;
  ULONG SID_More_Packets : 1;
  ULONG SID_Reserved3 : 1;
  ULONG SID_PortH : 2;
  ULONG SID_PortG : 2;
  ULONG SID_PortF : 2;
} SELF_ID_MORE, *PSELF_ID_MORE;