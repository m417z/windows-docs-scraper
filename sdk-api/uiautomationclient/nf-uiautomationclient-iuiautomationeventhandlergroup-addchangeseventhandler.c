HRESULT AddChangesEventHandler(
  [in] TreeScope                        scope,
  [in] int                              *changeTypes,
  [in] int                              changesCount,
  [in] IUIAutomationCacheRequest        *cacheRequest,
  [in] IUIAutomationChangesEventHandler *handler
);