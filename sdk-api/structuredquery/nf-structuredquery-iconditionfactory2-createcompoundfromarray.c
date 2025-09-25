HRESULT CreateCompoundFromArray(
  [in]  CONDITION_TYPE             ct,
  [in]  ICondition                 **ppcondSubs,
  [in]  ULONG                      cSubs,
  [in]  CONDITION_CREATION_OPTIONS cco,
  [in]  REFIID                     riid,
  [out] void                       **ppv
);