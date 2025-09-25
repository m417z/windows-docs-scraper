HRESULT AddChangesEventHandler(
  [in] IUIAutomationElement             *element,
  [in] TreeScope                        scope,
  [in] int                              *changeTypes,
  [in] int                              changesCount,
  [in] IUIAutomationCacheRequest        *pCacheRequest,
  [in] IUIAutomationChangesEventHandler *handler
);