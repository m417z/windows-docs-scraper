typedef struct _EVENT_DATA_DESCRIPTOR {
  ULONGLONG Ptr;
  ULONG     Size;
  union {
    ULONG Reserved;
    struct {
      UCHAR  Type;
      UCHAR  Reserved1;
      USHORT Reserved2;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
} EVENT_DATA_DESCRIPTOR, *PEVENT_DATA_DESCRIPTOR;