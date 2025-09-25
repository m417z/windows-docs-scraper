typedef struct {
  ULONG  PresentationTimeStamp;
  ULONG  SourceClockReference;
  union {
    struct {
      USHORT Counter : 11;
      USHORT Reserved : 5;
    };
    USHORT SCRToken;
  };
  USHORT Reserved0;
  ULONG  Reserved1;
} KSSTREAM_UVC_METADATATYPE_TIMESTAMP, *PKSSTREAM_UVC_METADATATYPE_TIMESTAMP;