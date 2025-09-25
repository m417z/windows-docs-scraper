HRESULT FindAttribute(
  [in]          TEXTATTRIBUTEID        attr,
  [in]          VARIANT                val,
  [in]          BOOL                   backward,
  [out, retval] IUIAutomationTextRange **found
);