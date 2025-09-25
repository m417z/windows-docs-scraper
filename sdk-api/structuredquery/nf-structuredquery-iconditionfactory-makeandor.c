HRESULT MakeAndOr(
  [in]          CONDITION_TYPE ct,
  [in]          IEnumUnknown   *peuSubs,
  [in]          BOOL           fSimplify,
  [out, retval] ICondition     **ppcResult
);