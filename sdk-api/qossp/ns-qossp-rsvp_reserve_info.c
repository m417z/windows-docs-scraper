typedef struct _RSVP_RESERVE_INFO {
  QOS_OBJECT_HDR     ObjectHdr;
  ULONG              Style;
  ULONG              ConfirmRequest;
  LPRSVP_POLICY_INFO PolicyElementList;
  ULONG              NumFlowDesc;
  LPFLOWDESCRIPTOR   FlowDescList;
} RSVP_RESERVE_INFO, *LPRSVP_RESERVE_INFO;