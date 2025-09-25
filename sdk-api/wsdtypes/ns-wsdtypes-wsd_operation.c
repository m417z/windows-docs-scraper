typedef struct _WSD_OPERATION {
  WSDXML_TYPE       *RequestType;
  WSDXML_TYPE       *ResponseType;
  WSD_STUB_FUNCTION RequestStubFunction;
} WSD_OPERATION;