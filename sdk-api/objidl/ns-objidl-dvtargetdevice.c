typedef struct tagDVTARGETDEVICE {
  DWORD tdSize;
  WORD  tdDriverNameOffset;
  WORD  tdDeviceNameOffset;
  WORD  tdPortNameOffset;
  WORD  tdExtDevmodeOffset;
  BYTE  tdData[1];
} DVTARGETDEVICE;