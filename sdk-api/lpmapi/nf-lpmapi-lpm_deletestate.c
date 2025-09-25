VOID LPM_DeleteState(
  [in] RSVP_HOP     *pRcvdIfAddr,
  [in] MSG_TYPE     RsvpMsgType,
  [in] RSVP_SESSION *pRsvpSession,
  [in] RSVP_HOP     *pRsvpFromHop,
  [in] RESV_STYLE   *pResvStyle,
  [in] int          FilterSpecCount,
  [in] FILTER_SPEC  **ppFilterSpecList,
  [in] int          TearDownReason
);