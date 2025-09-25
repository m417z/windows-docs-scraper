typedef struct _PinInfo {
  IBaseFilter   *pFilter;
  PIN_DIRECTION dir;
  WCHAR         achName[128];
} PIN_INFO;