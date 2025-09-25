HRESULT AddPropertyChangedEventHandler(
  [in] TreeScope                                scope,
  [in] IUIAutomationCacheRequest                *cacheRequest,
  [in] IUIAutomationPropertyChangedEventHandler *handler,
  [in] PROPERTYID                               *propertyArray,
       int                                      propertyCount
);