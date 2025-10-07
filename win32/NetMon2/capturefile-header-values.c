typedef struct _CAPTUREFILE_HEADER_VALUES {
  DWORD      Signature;
  BYTE       BCDVerMinor;
  BYTE       BCDVerMajor;
  WORD       MacType;
  SYSTEMTIME TimeStamp;
  DWORD      FrameTableOffset;
  DWORD      FrameTableLength;
  DWORD      UserDataOffset;
  DWORD      UserDataLength;
  DWORD      CommentDataOffset;
  DWORD      CommentDataLength;
  DWORD      StatisticsOffset;
  DWORD      StatisticsLength;
  DWORD      NetworkInfoOffset;
  DWORD      NetworkInfoLength;
  DWORD      ConversationStatsOffset;
  DWORD      ConversationStatsLength;
} CAPTUREFILE_HEADER_VALUES, *LPCAPTUREFILE_HEADER_VALUES;