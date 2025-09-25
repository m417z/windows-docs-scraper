typedef struct _MTP_COMMAND_DATA_IN {
  WORD  OpCode;
  DWORD NumParams;
  DWORD Params[MTP_COMMAND_MAX_PARAMS];
  DWORD NextPhase;
  DWORD CommandWriteDataSize;
  BYTE  CommandWriteData[1];
} MTP_COMMAND_DATA_IN, *PMTP_COMMAND_DATA_IN;