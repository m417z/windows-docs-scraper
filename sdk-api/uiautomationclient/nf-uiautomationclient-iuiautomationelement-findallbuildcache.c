HRESULT FindAllBuildCache(
  [in]          TreeScope                 scope,
  [in]          IUIAutomationCondition    *condition,
  [in]          IUIAutomationCacheRequest *cacheRequest,
  [out, retval] IUIAutomationElementArray **found
);