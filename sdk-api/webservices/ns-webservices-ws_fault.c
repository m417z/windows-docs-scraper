typedef struct _WS_FAULT {
  WS_FAULT_CODE   *code;
  WS_FAULT_REASON *reasons;
  ULONG           reasonCount;
  WS_STRING       actor;
  WS_STRING       node;
  WS_XML_BUFFER   *detail;
} WS_FAULT;