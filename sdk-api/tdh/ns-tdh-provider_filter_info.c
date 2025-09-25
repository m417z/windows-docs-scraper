typedef struct _PROVIDER_FILTER_INFO {
  UCHAR               Id;
  UCHAR               Version;
  ULONG               MessageOffset;
  ULONG               Reserved;
  ULONG               PropertyCount;
  EVENT_PROPERTY_INFO EventPropertyInfoArray[ANYSIZE_ARRAY];
} PROVIDER_FILTER_INFO, *PPROVIDER_FILTER_INFO;