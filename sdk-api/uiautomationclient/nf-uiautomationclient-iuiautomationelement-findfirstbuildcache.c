HRESULT FindFirstBuildCache(
  [in]          TreeScope                 scope,
  [in]          IUIAutomationCondition    *condition,
  [in]          IUIAutomationCacheRequest *cacheRequest,
  [out, retval] IUIAutomationElement      **found
);