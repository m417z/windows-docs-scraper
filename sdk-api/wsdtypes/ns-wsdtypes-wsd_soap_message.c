typedef struct _WSD_SOAP_MESSAGE {
  WSD_SOAP_HEADER Header;
  void            *Body;
  WSDXML_TYPE     *BodyType;
} WSD_SOAP_MESSAGE;