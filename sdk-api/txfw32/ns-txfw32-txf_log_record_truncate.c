typedef struct _TXF_LOG_RECORD_TRUNCATE {
  USHORT   Version;
  USHORT   RecordType;
  ULONG    RecordLength;
  ULONG    Flags;
  TXF_ID   TxfFileId;
  GUID     KtmGuid;
  LONGLONG NewFileSize;
  ULONG    FileNameLength;
  ULONG    FileNameByteOffsetInStructure;
} TXF_LOG_RECORD_TRUNCATE, *PTXF_LOG_RECORD_TRUNCATE;