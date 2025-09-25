typedef struct _WSD_HANDLER_CONTEXT {
  PWSD_SOAP_MESSAGE_HANDLER Handler;
  void                      *PVoid;
  IUnknown                  *Unknown;
} WSD_HANDLER_CONTEXT;