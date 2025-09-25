typedef struct _WWAN_PIN_ACTION {
  WWAN_PIN_TYPE      PinType;
  WWAN_PIN_OPERATION PinOperation;
  WCHAR              Pin[WWAN_PIN_LEN];
  WCHAR              NewPin[WWAN_PIN_LEN];
  BOOLEAN            RequestPinOperationPrompt;
} WWAN_PIN_ACTION, *PWWAN_PIN_ACTION;