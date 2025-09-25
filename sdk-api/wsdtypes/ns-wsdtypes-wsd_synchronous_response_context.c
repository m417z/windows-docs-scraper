typedef struct _WSD_SYNCHRONOUS_RESPONSE_CONTEXT {
  HRESULT                      hr;
  HANDLE                       eventHandle;
  struct IWSDMessageParameters *messageParameters;
  void                         *results;
} WSD_SYNCHRONOUS_RESPONSE_CONTEXT;