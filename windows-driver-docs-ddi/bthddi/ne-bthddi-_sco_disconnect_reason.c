typedef enum _SCO_DISCONNECT_REASON {
  ScoHciDisconnect,
  ScoDisconnectRequest,
  ScoRadioPoweredDown,
  ScoHardwareRemoval
} SCO_DISCONNECT_REASON, *PSCO_DISCONNECT_REASON;