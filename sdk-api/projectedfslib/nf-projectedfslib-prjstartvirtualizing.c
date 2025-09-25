HRESULT PrjStartVirtualizing(
  [in]           PCWSTR                               virtualizationRootPath,
  [in]           const PRJ_CALLBACKS                  *callbacks,
  [in, optional] const void                           *instanceContext,
  [in, optional] const PRJ_STARTVIRTUALIZING_OPTIONS  *options,
  [out]          PRJ_NAMESPACE_VIRTUALIZATION_CONTEXT *namespaceVirtualizationContext
);