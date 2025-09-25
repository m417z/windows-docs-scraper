typedef struct _TXF_LOG_RECORD_AFFECTED_FILE {
  USHORT Version;
  ULONG  RecordLength;
  ULONG  Flags;
  TXF_ID TxfFileId;
  GUID   KtmGuid;
  ULONG  FileNameLength;
  ULONG  FileNameByteOffsetInStructure;
} TXF_LOG_RECORD_AFFECTED_FILE, *PTXF_LOG_RECORD_AFFECTED_FILE;