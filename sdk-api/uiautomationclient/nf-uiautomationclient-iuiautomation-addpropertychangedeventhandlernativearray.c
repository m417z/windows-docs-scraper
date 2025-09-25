HRESULT AddPropertyChangedEventHandlerNativeArray(
  [in] IUIAutomationElement                     *element,
  [in] TreeScope                                scope,
  [in] IUIAutomationCacheRequest                *cacheRequest,
  [in] IUIAutomationPropertyChangedEventHandler *handler,
  [in] PROPERTYID                               *propertyArray,
  [in] int                                      propertyCount
);