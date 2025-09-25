HRESULT FindFirstWithOptionsBuildCache(
  [in]           TreeScope                 scope,
  [in]           IUIAutomationCondition    *condition,
  [in]           IUIAutomationCacheRequest *cacheRequest,
                 TreeTraversalOptions      traversalOptions,
  [in, optional] IUIAutomationElement      *root,
  [out, retval]  IUIAutomationElement      **found
);