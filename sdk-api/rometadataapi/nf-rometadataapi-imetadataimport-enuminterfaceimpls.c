HRESULT EnumInterfaceImpls(
  [in, out]     HCORENUM           *phEnum,
  [in]          mdTypeDef          td,
  [out]         mdInterfaceImpl [] rImpls,
  [in]          ULONG              cMax,
  [out, retval] ULONG              *pcImpls
);