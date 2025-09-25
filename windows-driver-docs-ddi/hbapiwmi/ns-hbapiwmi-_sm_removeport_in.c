typedef struct _SM_RemovePort_IN {
  UCHAR PortWWN[8];
  ULONG EventType;
} SM_RemovePort_IN, *PSM_RemovePort_IN;