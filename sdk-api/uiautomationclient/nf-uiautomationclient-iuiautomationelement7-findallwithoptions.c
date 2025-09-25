HRESULT FindAllWithOptions(
                 TreeScope                 scope,
  [in]           IUIAutomationCondition    *condition,
                 TreeTraversalOptions      traversalOptions,
  [in, optional] IUIAutomationElement      *root,
  [out]          IUIAutomationElementArray **found
);