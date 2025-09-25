typedef struct _HTTP_UNKNOWN_HEADER {
  USHORT NameLength;
  USHORT RawValueLength;
  PCSTR  pName;
  PCSTR  pRawValue;
} HTTP_UNKNOWN_HEADER, *PHTTP_UNKNOWN_HEADER;