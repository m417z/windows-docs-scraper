HRESULT EnumTypeRefs(
  [in, out]     HCORENUM     *phEnum,
  [out]         mdTypeRef [] rgTypeRefs,
  [in]          ULONG        cMax,
  [out, retval] ULONG        *pcTypeRefs
);