typedef struct _HW_EVENT_DESCRIPTOR {
  BOOLEAN        Enable;
  PKSEVENT_ENTRY EventEntry;
  PKSEVENTDATA   EventData;
  union {
#if ...
    _HW_STREAM_OBJECT           *StreamObject;
#else
    struct _HW_STREAM_OBJECT    *StreamObject;
#endif
#if ...
    _HW_DEVICE_EXTENSION        *DeviceExtension;
#else
    struct _HW_DEVICE_EXTENSION *DeviceExtension;
#endif
  };
  ULONG          EnableEventSetIndex;
  PVOID          HwInstanceExtension;
#if ...
  ULONG          Reserved;
#else
  ULONG          Reserved[2];
#endif
} HW_EVENT_DESCRIPTOR, *PHW_EVENT_DESCRIPTOR;