typedef struct _MTP_COMMAND_DATA_OUT {
  WORD  ResponseCode;
  DWORD NumParams;
  DWORD Params[MTP_RESPONSE_MAX_PARAMS];
  DWORD CommandReadDataSize;
  BYTE  CommandReadData[1];
} MTP_COMMAND_DATA_OUT, *PMTP_COMMAND_DATA_OUT;