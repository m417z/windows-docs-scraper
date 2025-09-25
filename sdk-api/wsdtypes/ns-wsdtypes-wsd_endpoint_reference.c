typedef struct _WSD_ENDPOINT_REFERENCE {
  const WCHAR              *Address;
  WSD_REFERENCE_PROPERTIES ReferenceProperties;
  WSD_REFERENCE_PARAMETERS ReferenceParameters;
  WSDXML_NAME              *PortType;
  WSDXML_NAME              *ServiceName;
  WSDXML_ELEMENT           *Any;
} WSD_ENDPOINT_REFERENCE;