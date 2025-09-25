typedef struct _WS_XML_DICTIONARY {
  GUID          guid;
  WS_XML_STRING *strings;
  ULONG         stringCount;
  BOOL          isConst;
} WS_XML_DICTIONARY;