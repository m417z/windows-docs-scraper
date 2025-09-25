HRESULT EnumClassesOfCategories(
  [in]  ULONG          cImplemented,
  [in]  const CATID [] rgcatidImpl,
  [in]  ULONG          cRequired,
  [in]  const CATID [] rgcatidReq,
  [out] IEnumGUID      **ppenumClsid
);