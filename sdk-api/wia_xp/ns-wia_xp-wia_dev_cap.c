typedef struct _WIA_DEV_CAP {
  GUID  guid;
  ULONG ulFlags;
  BSTR  bstrName;
  BSTR  bstrDescription;
  BSTR  bstrIcon;
  BSTR  bstrCommandline;
} WIA_DEV_CAP, *PWIA_DEV_CAP, WIA_EVENT_HANDLER, *PWIA_EVENT_HANDLER;