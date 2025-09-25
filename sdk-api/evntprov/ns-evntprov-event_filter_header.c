typedef struct _EVENT_FILTER_HEADER {
  USHORT    Id;
  UCHAR     Version;
  UCHAR     Reserved[5];
  ULONGLONG InstanceId;
  ULONG     Size;
  ULONG     NextOffset;
} EVENT_FILTER_HEADER, *PEVENT_FILTER_HEADER;