typedef struct _WSD_SOAP_HEADER {
  const WCHAR            *To;
  const WCHAR            *Action;
  const WCHAR            *MessageID;
  WSD_HEADER_RELATESTO   RelatesTo;
  WSD_ENDPOINT_REFERENCE *ReplyTo;
  WSD_ENDPOINT_REFERENCE *From;
  WSD_ENDPOINT_REFERENCE *FaultTo;
  WSD_APP_SEQUENCE       *AppSequence;
  WSDXML_ELEMENT         *AnyHeaders;
} WSD_SOAP_HEADER;