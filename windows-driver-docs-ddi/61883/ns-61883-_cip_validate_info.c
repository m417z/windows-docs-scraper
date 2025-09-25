typedef struct _CIP_VALIDATE_INFO {
  HANDLE     hConnect;
  PVOID      Context;
  CYCLE_TIME TimeStamp;
  PUCHAR     Packet;
} CIP_VALIDATE_INFO, *PCIP_VALIDATE_INFO;