HRESULT GetInterfacesIfExist(
  [in]           BSTR          WDTFInterfaceName,
  [in, optional] VARIANT       MoreTargets,
  [in, optional] VARIANT       MonikerSuffix,
  [out, retval]  IWDTFActions2 **ppInterface
);