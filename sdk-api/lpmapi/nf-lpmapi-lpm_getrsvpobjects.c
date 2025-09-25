ULONG LPM_GetRsvpObjects(
  [in]  RHANDLE       PcmReqHandle,
  [in]  ULONG         MaxPdSize,
  [in]  RSVP_HOP      *SendingIntfAddr,
  [in]  RSVP_MSG_OBJS *pRsvpMsgObjs,
  [out] int           *pRsvpObjectsCount,
  [out] RsvpObjHdr    ***pppRsvpObjects,
  [out] void          *Reserved
);