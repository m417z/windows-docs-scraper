typedef struct _SPEED_MAP {
  USHORT SPD_Length;
  USHORT SPD_CRC;
  ULONG  SPD_Generation;
  UCHAR  SPD_Speed_Code[4032];
} SPEED_MAP, *PSPEED_MAP;