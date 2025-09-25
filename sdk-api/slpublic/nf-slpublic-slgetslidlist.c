HRESULT SLGetSLIDList(
  [in]           HSLC       hSLC,
  [in]           SLIDTYPE   eQueryIdType,
  [in, optional] const SLID *pQueryId,
  [in]           SLIDTYPE   eReturnIdType,
  [out]          UINT       *pnReturnIds,
  [out]          SLID       **ppReturnIds
);