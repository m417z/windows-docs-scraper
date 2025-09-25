typedef enum _ONEX_AUTH_RESTART_REASON {
  OneXRestartReasonPeerInitiated,
  OneXRestartReasonMsmInitiated,
  OneXRestartReasonOneXHeldStateTimeout,
  OneXRestartReasonOneXAuthTimeout,
  OneXRestartReasonOneXConfigurationChanged,
  OneXRestartReasonOneXUserChanged,
  OneXRestartReasonQuarantineStateChanged,
  OneXRestartReasonAltCredsTrial,
  OneXRestartReasonInvalid
} ONEX_AUTH_RESTART_REASON, PONEX_AUTH_RESTART_REASON;