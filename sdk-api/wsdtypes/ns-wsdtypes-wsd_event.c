typedef struct _WSD_EVENT {
  HRESULT                      Hr;
  DWORD                        EventType;
  WCHAR                        *DispatchTag;
  WSD_HANDLER_CONTEXT          HandlerContext;
  WSD_SOAP_MESSAGE             *Soap;
  WSD_OPERATION                *Operation;
  struct IWSDMessageParameters *MessageParameters;
} WSD_EVENT;