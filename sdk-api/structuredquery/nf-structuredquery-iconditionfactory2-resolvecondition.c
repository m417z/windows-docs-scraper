HRESULT ResolveCondition(
  [in]           ICondition                      *pc,
  [in]           STRUCTURED_QUERY_RESOLVE_OPTION sqro,
  [in, optional] const SYSTEMTIME                *pstReferenceTime,
  [in]           REFIID                          riid,
  [out]          void                            **ppv
);