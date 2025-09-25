typedef enum _EAPHOST_AUTH_STATUS {
  EapHostInvalidSession = 0,
  EapHostAuthNotStarted,
  EapHostAuthIdentityExchange,
  EapHostAuthNegotiatingType,
  EapHostAuthInProgress,
  EapHostAuthSucceeded,
  EapHostAuthFailed
} EAPHOST_AUTH_STATUS;