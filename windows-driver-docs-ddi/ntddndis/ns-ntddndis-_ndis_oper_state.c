typedef struct _NDIS_OPER_STATE {
  NDIS_OBJECT_HEADER Header;
  NET_IF_OPER_STATUS OperationalStatus;
  ULONG              OperationalStatusFlags;
} NDIS_OPER_STATE, *PNDIS_OPER_STATE;