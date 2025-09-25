HRESULT GenerateForLeaf(
  [in]          IConditionFactory   *pConditionFactory,
  [in]          LPCWSTR             pszPropertyName,
  [in]          CONDITION_OPERATION cop,
  [in]          LPCWSTR             pszValueType,
  [in]          LPCWSTR             pszValue,
  [in]          LPCWSTR             pszValue2,
  [in]          IRichChunk          *pPropertyNameTerm,
  [in]          IRichChunk          *pOperationTerm,
  [in]          IRichChunk          *pValueTerm,
  [in]          BOOL                automaticWildcard,
  [out]         BOOL                *pNoStringQuery,
  [out, retval] ICondition          **ppQueryExpression
);