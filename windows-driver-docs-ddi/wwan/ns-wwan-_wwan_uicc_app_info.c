typedef struct _WWAN_UICC_APP_INFO {
  WWAN_UICC_APP_TYPE AppType;
  ULONG              AppIdSize;
  BYTE               AppId[WWAN_UICC_APP_ID_MAX_LEN];
  ULONG              AppNameLength;
  BYTE               AppName[WWAN_UICC_APP_NAME_MAX_LEN];
  ULONG              NumPins;
  BYTE               PinRef[WWAN_UICC_PINREF_MAX];
} WWAN_UICC_APP_INFO, *PWWAN_UICC_APP_INFO;