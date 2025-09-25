typedef struct NCRYPT_PROTECT_STREAM_INFO {
  PFNCryptStreamOutputCallback pfnStreamOutput;
  void                         *pvCallbackCtxt;
} NCRYPT_PROTECT_STREAM_INFO;