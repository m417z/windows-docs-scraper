typedef struct _WWAN_UICC_APP_LIST {
  ULONG Version;
  ULONG AppCount;
  ULONG ActiveAppIndex;
  ULONG AppListSize;
  BYTE  Response[ANYSIZE_ARRAY];
} WWAN_UICC_APP_LIST, *PWWAN_UICC_APP_LIST;