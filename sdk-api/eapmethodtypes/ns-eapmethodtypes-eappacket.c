typedef struct tagEapPacket {
  BYTE Code;
  BYTE Id;
  BYTE Length[2];
  BYTE Data[1];
} EapPacket;