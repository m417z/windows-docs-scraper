typedef struct {
  GUID  PowerSetting;
  DWORD DataLength;
  UCHAR Data[1];
} POWERBROADCAST_SETTING, *PPOWERBROADCAST_SETTING;