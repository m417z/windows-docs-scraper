HRESULT FindText(
  [in]          BSTR                   text,
  [in]          BOOL                   backward,
  [in]          BOOL                   ignoreCase,
  [out, retval] IUIAutomationTextRange **found
);