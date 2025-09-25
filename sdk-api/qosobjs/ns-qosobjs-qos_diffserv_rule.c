typedef struct _QOS_DIFFSERV_RULE {
  UCHAR InboundDSField;
  UCHAR ConformingOutboundDSField;
  UCHAR NonConformingOutboundDSField;
  UCHAR ConformingUserPriority;
  UCHAR NonConformingUserPriority;
} QOS_DIFFSERV_RULE, *LPQOS_DIFFSERV_RULE;