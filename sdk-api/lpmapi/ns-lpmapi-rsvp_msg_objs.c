typedef struct rsvpmsgobjs {
  MSG_TYPE     RsvpMsgType;
  RSVP_SESSION *pRsvpSession;
  RSVP_HOP     *pRsvpFromHop;
  RSVP_HOP     *pRsvpToHop;
  RESV_STYLE   *pResvStyle;
  RSVP_SCOPE   *pRsvpScope;
  int          FlowDescCount;
  FLOW_DESC    *pFlowDescs;
  int          PdObjectCount;
  POLICY_DATA  **ppPdObjects;
  ERROR_SPEC   *pErrorSpec;
  ADSPEC       *pAdspec;
} RSVP_MSG_OBJS;