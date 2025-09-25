HRESULT CreatePropertyConditionEx(
  [in]          PROPERTYID             propertyId,
  [in]          VARIANT                value,
  [in]          PropertyConditionFlags flags,
  [out, retval] IUIAutomationCondition **newCondition
);