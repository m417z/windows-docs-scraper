HRESULT ElementFromIAccessibleBuildCache(
  [in]          IAccessible               *accessible,
  [in]          int                       childId,
  [in]          IUIAutomationCacheRequest *cacheRequest,
  [out, retval] IUIAutomationElement      **element
);