typedef struct _ROOTHUB_30PORT_INFO_EX {
  ROOTHUB_30PORT_INFO                         Info;
  USHORT                                      MaxSpeedsCount;
  USHORT                                      SpeedsCount;
  PUSB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED Speeds;
} ROOTHUB_30PORT_INFO_EX, *PROOTHUB_30PORT_INFO_EX;