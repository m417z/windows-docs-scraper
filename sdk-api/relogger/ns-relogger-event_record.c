typedef struct _EVENT_RECORD {
  EVENT_HEADER                     EventHeader;
  ETW_BUFFER_CONTEXT               BufferContext;
  USHORT                           ExtendedDataCount;
  USHORT                           UserDataLength;
  PEVENT_HEADER_EXTENDED_DATA_ITEM ExtendedData;
  PVOID                            UserData;
  PVOID                            UserContext;
} EVENT_RECORD, *PEVENT_RECORD;