ULONG LPM_AdmitRsvpMsg(
  [in]  RHANDLE         PcmReqHandle,
  [in]  RSVP_HOP        *pRecvdIntf,
  [in]  RSVP_MSG_OBJS   *pRsvpMsgObjs,
  [in]  int             RcvdRsvpMsgLength,
  [in]  UCHAR           *RcvdRsvpMsg,
  [out] ULONG           *pulPcmActionFlags,
  [out] POLICY_DECISION *pPolicyDecisions,
  [out] void            *Reserved
);