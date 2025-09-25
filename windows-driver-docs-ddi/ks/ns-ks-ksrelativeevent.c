typedef struct {
  ULONG       Size;
  ULONG       Flags;
  union {
    HANDLE ObjectHandle;
    PVOID  ObjectPointer;
  };
  PVOID       Reserved;
  KSEVENT     Event;
  KSEVENTDATA EventData;
} KSRELATIVEEVENT;