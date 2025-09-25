HRESULT FindAllWithOptionsBuildCache(
  [in]          TreeScope                 scope,
  [in]          IUIAutomationCondition    *condition,
  [in]          IUIAutomationCacheRequest *cacheRequest,
  [in]          TreeTraversalOptions      traversalOptions,
  [in]          IUIAutomationElement      *root,
  [out, retval] IUIAutomationElementArray **found
);