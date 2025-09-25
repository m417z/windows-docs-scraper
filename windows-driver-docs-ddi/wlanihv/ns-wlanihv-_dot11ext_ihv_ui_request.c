typedef struct _DOT11EXT_IHV_UI_REQUEST {
  DWORD dwSessionId;
  GUID  guidUIRequest;
  CLSID UIPageClsid;
  DWORD dwByteCount;
  BYTE  *pvUIRequest;
} DOT11EXT_IHV_UI_REQUEST, *PDOT11EXT_IHV_UI_REQUEST;