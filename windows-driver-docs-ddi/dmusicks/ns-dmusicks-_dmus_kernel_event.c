typedef struct _DMUS_KERNEL_EVENT {
  BYTE               bReserved;
  BYTE               cbStruct;
  USHORT             cbEvent;
  USHORT             usChannelGroup;
  USHORT             usFlags;
  REFERENCE_TIME     ullPresTime100ns;
  ULONGLONG          ullBytePosition;
  _DMUS_KERNEL_EVENT *pNextEvt;
  union {
    BYTE               abData[sizeof(PBYTE)];
    PBYTE              pbData;
    _DMUS_KERNEL_EVENT *pPackageEvt;
  } uData;
} DMUS_KERNEL_EVENT, *PDMUS_KERNEL_EVENT;