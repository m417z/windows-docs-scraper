typedef struct _WWAN_PIN_DESC {
  WWAN_PIN_MODE   PinMode;
  WWAN_PIN_FORMAT PinFormat;
  ULONG           PinLengthMin;
  ULONG           PinLengthMax;
} WWAN_PIN_DESC, *PWWAN_PIN_DESC;