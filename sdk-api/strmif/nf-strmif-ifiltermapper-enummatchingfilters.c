HRESULT EnumMatchingFilters(
  [out] IEnumRegFilters **ppEnum,
  [in]  DWORD           dwMerit,
        BOOL            bInputNeeded,
  [in]  CLSID           clsInMaj,
  [in]  CLSID           clsInSub,
  [in]  BOOL            bRender,
  [in]  BOOL            bOututNeeded,
  [in]  CLSID           clsOutMaj,
  [in]  CLSID           clsOutSub
);