HRESULT UiaAddEvent(
  [in]  HUIANODE         hnode,
  [in]  EVENTID          eventId,
  [in]  UiaEventCallback *pCallback,
  [in]  TreeScope        scope,
  [in]  PROPERTYID       *pProperties,
  [in]  int              cProperties,
  [in]  UiaCacheRequest  *pRequest,
  [out] HUIAEVENT        *phEvent
);