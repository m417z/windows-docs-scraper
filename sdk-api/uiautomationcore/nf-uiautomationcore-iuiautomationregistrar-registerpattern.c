HRESULT RegisterPattern(
  [in]  const UIAutomationPatternInfo *pattern,
  [out] PATTERNID                     *pPatternId,
  [out] PROPERTYID                    *pPatternAvailablePropertyId,
  [in]  UINT                          propertyIdCount,
  [out] PROPERTYID                    *pPropertyIds,
  [in]  UINT                          eventIdCount,
  [out] EVENTID                       *pEventIds
);