typedef struct _CLASSIC_EVENT_ID {
  GUID  EventGuid;
  UCHAR Type;
  UCHAR Reserved[7];
} CLASSIC_EVENT_ID, *PCLASSIC_EVENT_ID;