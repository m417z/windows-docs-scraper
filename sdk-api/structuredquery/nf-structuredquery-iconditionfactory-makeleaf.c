HRESULT MakeLeaf(
  [in]          LPCWSTR             pszPropertyName,
  [in]          CONDITION_OPERATION cop,
  [in]          LPCWSTR             pszValueType,
  [in]          const PROPVARIANT   *ppropvar,
  [in]          IRichChunk          *pPropertyNameTerm,
  [in]          IRichChunk          *pOperationTerm,
  [in]          IRichChunk          *pValueTerm,
  [in]          BOOL                fExpand,
  [out, retval] ICondition          **ppcResult
);