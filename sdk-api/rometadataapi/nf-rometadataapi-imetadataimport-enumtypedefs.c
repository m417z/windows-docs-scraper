HRESULT EnumTypeDefs(
  [in, out]     HCORENUM     *phEnum,
  [out]         mdTypeDef [] rgTypeDefs,
  [in]          ULONG        cMax,
  [out, retval] ULONG        *pcTypeDefs
);