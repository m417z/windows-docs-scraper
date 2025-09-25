HRESULT Resolve(
  [in]          ICondition                      *pc,
  [in]          STRUCTURED_QUERY_RESOLVE_OPTION sqro,
  [in]          const SYSTEMTIME                *pstReferenceTime,
  [out, retval] ICondition                      **ppcResolved
);