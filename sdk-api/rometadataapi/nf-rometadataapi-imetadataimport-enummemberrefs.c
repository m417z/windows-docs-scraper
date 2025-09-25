HRESULT EnumMemberRefs(
  [in, out] HCORENUM       *phEnum,
  [in]      mdToken        tkParent,
  [out]     mdMemberRef [] rgMemberRefs,
  [in]      ULONG          cMax,
  [out]     ULONG          *pcTokens
);