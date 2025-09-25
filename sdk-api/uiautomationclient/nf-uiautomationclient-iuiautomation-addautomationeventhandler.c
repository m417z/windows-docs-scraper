HRESULT AddAutomationEventHandler(
  [in] EVENTID                   eventId,
  [in] IUIAutomationElement      *element,
  [in] TreeScope                 scope,
  [in] IUIAutomationCacheRequest *cacheRequest,
  [in] IUIAutomationEventHandler *handler
);