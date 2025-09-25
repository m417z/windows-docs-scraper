typedef enum _PPP_EAP_ACTION {
  EAPACTION_NoAction,
  EAPACTION_Authenticate,
  EAPACTION_Done,
  EAPACTION_SendAndDone,
  EAPACTION_Send,
  EAPACTION_SendWithTimeout,
  EAPACTION_SendWithTimeoutInteractive,
  EAPACTION_IndicateTLV,
  EAPACTION_IndicateIdentity
} PPP_EAP_ACTION;