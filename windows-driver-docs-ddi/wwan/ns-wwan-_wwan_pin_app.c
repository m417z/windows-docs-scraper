typedef struct _WWAN_PIN_APP {
  ULONG Version;
  BYTE  AppIdLength;
  BYTE  AppId[WWAN_UICC_APP_ID_MAX_LEN];
} WWAN_PIN_APP, *PWWAN_PIN_APP;