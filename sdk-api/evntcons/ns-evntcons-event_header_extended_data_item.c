typedef struct _EVENT_HEADER_EXTENDED_DATA_ITEM {
  USHORT    Reserved1;
  USHORT    ExtType;
  struct {
    USHORT Linkage : 1;
    USHORT Reserved2 : 15;
  };
  USHORT    DataSize;
  ULONGLONG DataPtr;
} EVENT_HEADER_EXTENDED_DATA_ITEM, *PEVENT_HEADER_EXTENDED_DATA_ITEM;