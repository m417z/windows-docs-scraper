HRESULT EnumerateTargets(
  [in]      BSTR              FarmName,
  [in]      BSTR              EnvName,
  [in]      TS_SB_SORT_BY     sortByFieldId,
  [in]      BSTR              sortyByPropName,
  [in, out] DWORD             *pdwCount,
  [out]     ITsSbTarget ** [] pVal
);