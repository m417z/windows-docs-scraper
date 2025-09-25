HRESULT CreateNamespace(
  [in]  WDSTRANSPORT_NAMESPACE_TYPE NamespaceType,
  [in]  BSTR                        bszNamespaceName,
  [in]  BSTR                        bszContentProvider,
  [in]  BSTR                        bszConfiguration,
  [out] IWdsTransportNamespace      **ppWdsTransportNamespace
);