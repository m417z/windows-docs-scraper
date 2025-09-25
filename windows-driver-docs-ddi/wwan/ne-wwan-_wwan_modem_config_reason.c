typedef enum _WWAN_MODEM_CONFIG_REASON {
  WwanModemConfigReasonNone,
  WwanModemConfigReasonSIMDetected,
  WwanModemConfigReasonNOSIM,
  WwanModemConfigReasonIMSIReset,
  WwanModemConfigReasonActivationFailure,
  WwanModemConfigReasonConfigFileUpdate,
  WwanModemConfigReasonModemReset,
  WwanModemConfigReasonModemRecovery,
  WwanModemConfigReasonMax
} WWAN_MODEM_CONFIG_REASON, *PWWAN_MODEM_CONFIG_REASON;