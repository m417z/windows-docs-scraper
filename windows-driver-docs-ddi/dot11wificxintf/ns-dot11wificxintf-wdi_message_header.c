typedef struct _WDI_MESSAGE_HEADER {
  WDI_PORT_ID PortId;
  UINT16      Reserved;
  NDIS_STATUS Status;
  UINT32      TransactionId;
  UINT32      IhvSpecificId;
} WDI_MESSAGE_HEADER, *PWDI_MESSAGE_HEADER;