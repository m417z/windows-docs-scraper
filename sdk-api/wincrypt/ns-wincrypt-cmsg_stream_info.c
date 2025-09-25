typedef struct _CMSG_STREAM_INFO {
  DWORD                  cbContent;
  PFN_CMSG_STREAM_OUTPUT pfnStreamOutput;
  void                   *pvArg;
} CMSG_STREAM_INFO, *PCMSG_STREAM_INFO;