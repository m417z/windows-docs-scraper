typedef struct _SELF_ID {
  ULONG SID_Phys_ID : 6;
  ULONG SID_Packet_ID : 2;
  ULONG SID_Gap_Count : 6;
  ULONG SID_Link_Active : 1;
  ULONG SID_Zero : 1;
  ULONG SID_Power_Class : 3;
  ULONG SID_Contender : 1;
  ULONG SID_Delay : 2;
  ULONG SID_Speed : 2;
  ULONG SID_More_Packets : 1;
  ULONG SID_Initiated_Rst : 1;
  ULONG SID_Port3 : 2;
  ULONG SID_Port2 : 2;
  ULONG SID_Port1 : 2;
} SELF_ID, *PSELF_ID;