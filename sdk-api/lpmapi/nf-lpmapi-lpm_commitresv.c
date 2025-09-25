VOID LPM_CommitResv(
  [in] RSVP_SESSION *RsvpSession,
  [in] RSVP_HOP     *FlowInstalledIntf,
  [in] RESV_STYLE   *RsvpStyle,
  [in] int          FilterSpecCount,
  [in] FILTER_SPEC  **ppFilterSpecList,
  [in] IS_FLOWSPEC  *pMergedFlowSpec,
  [in] ULONG        CommitDecision
);