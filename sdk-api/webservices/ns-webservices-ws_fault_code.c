typedef struct _WS_FAULT_CODE {
  WS_XML_QNAME          value;
  struct _WS_FAULT_CODE *subCode;
} WS_FAULT_CODE;