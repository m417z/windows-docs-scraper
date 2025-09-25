typedef struct _WWAN_PIN_INFO {
  WWAN_PIN_TYPE  PinType;
  WWAN_PIN_STATE PinState;
  ULONG          AttemptsRemaining;
} WWAN_PIN_INFO, *PWWAN_PIN_INFO;