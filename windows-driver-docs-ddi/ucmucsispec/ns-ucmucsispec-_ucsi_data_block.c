typedef struct _UCSI_DATA_BLOCK {
  UCSI_VERSION     UcsiVersion;
  UCSI_CCI         CCI;
  UCSI_CONTROL     Control;
  UCSI_MESSAGE_IN  MessageIn;
  UCSI_MESSAGE_OUT MessageOut;
} UCSI_DATA_BLOCK, *PUCSI_DATA_BLOCK;