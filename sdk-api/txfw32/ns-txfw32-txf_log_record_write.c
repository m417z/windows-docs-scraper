typedef struct _TXF_LOG_RECORD_WRITE {
  USHORT   Version;
  USHORT   RecordType;
  ULONG    RecordLength;
  ULONG    Flags;
  TXF_ID   TxfFileId;
  GUID     KtmGuid;
  LONGLONG ByteOffsetInFile;
  ULONG    NumBytesWritten;
  ULONG    ByteOffsetInStructure;
  ULONG    FileNameLength;
  ULONG    FileNameByteOffsetInStructure;
} TXF_LOG_RECORD_WRITE, *PTXF_LOG_RECORD_WRITE;