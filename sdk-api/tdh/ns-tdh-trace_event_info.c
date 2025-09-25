typedef struct _TRACE_EVENT_INFO {
  GUID                ProviderGuid;
  GUID                EventGuid;
  EVENT_DESCRIPTOR    EventDescriptor;
  DECODING_SOURCE     DecodingSource;
  ULONG               ProviderNameOffset;
  ULONG               LevelNameOffset;
  ULONG               ChannelNameOffset;
  ULONG               KeywordsNameOffset;
  ULONG               TaskNameOffset;
  ULONG               OpcodeNameOffset;
  ULONG               EventMessageOffset;
  ULONG               ProviderMessageOffset;
  ULONG               BinaryXMLOffset;
  ULONG               BinaryXMLSize;
  union {
    ULONG EventNameOffset;
    ULONG ActivityIDNameOffset;
  };
  union {
    ULONG EventAttributesOffset;
    ULONG RelatedActivityIDNameOffset;
  };
  ULONG               PropertyCount;
  ULONG               TopLevelPropertyCount;
  union {
    TEMPLATE_FLAGS Flags;
    struct {
      ULONG Reserved : 4;
      ULONG Tags : 28;
    };
  };
  EVENT_PROPERTY_INFO EventPropertyInfoArray[ANYSIZE_ARRAY];
} TRACE_EVENT_INFO;