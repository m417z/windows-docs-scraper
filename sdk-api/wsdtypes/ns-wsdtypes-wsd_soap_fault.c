typedef struct _WSD_SOAP_FAULT {
  WSD_SOAP_FAULT_CODE   *Code;
  WSD_SOAP_FAULT_REASON *Reason;
  const WCHAR           *Node;
  const WCHAR           *Role;
  WSDXML_ELEMENT        *Detail;
} WSD_SOAP_FAULT;