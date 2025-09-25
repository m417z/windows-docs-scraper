typedef struct _TXF_LOG_RECORD_BASE {
  USHORT Version;
  USHORT RecordType;
  ULONG  RecordLength;
} TXF_LOG_RECORD_BASE, *PTXF_LOG_RECORD_BASE;