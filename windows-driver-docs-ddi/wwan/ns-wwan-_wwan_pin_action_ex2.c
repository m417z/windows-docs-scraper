typedef struct _WWAN_PIN_ACTION_EX2 {
  WWAN_PIN_TYPE      PinType;
  WWAN_PIN_OPERATION PinOperation;
  WCHAR              Pin[WWAN_PIN_LEN];
  WCHAR              NewPin[WWAN_PIN_LEN];
  BYTE               AppIdLength;
  BYTE               AppId[WWAN_UICC_APP_ID_MAX_LEN];
} WWAN_PIN_ACTION_EX2, *PWWAN_PIN_ACTION_EX2;