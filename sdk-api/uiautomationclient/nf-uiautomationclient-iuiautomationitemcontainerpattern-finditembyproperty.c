HRESULT FindItemByProperty(
  [in]          IUIAutomationElement *pStartAfter,
  [in]          PROPERTYID           propertyId,
  [in]          VARIANT              value,
  [out, retval] IUIAutomationElement **pFound
);