HRESULT FindFirstWithOptions(
  [in]           TreeScope              scope,
  [in]           IUIAutomationCondition *condition,
                 TreeTraversalOptions   traversalOptions,
  [in, optional] IUIAutomationElement   *root,
  [out, retval]  IUIAutomationElement   **found
);