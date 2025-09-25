HRESULT RetrieveNamespaces(
  [in]  BSTR                    bszContentProvider,
  [in]  BSTR                    bszNamespaceName,
  [in]  VARIANT_BOOL            bIncludeTombstones,
  [out] IWdsTransportCollection **ppWdsTransportNamespaces
);