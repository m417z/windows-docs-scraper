typedef struct ETW_BUFFER_HEADER {
  ULONG              Reserved1[4];
  LARGE_INTEGER      TimeStamp;
  ULONG              Reserved2[4];
  ETW_BUFFER_CONTEXT ClientContext;
  ULONG              Reserved3;
  ULONG              FilledBytes;
  ULONG              Reserved4[5];
} ETW_BUFFER_HEADER;