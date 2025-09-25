HRESULT DrtCreatePnrpBootstrapResolver(
  [in]           BOOL                   fPublish,
  [in]           PCWSTR                 pwzPeerName,
  [in, optional] PCWSTR                 pwzCloudName,
  [in, optional] PCWSTR                 pwzPublishingIdentity,
  [out]          DRT_BOOTSTRAP_PROVIDER **ppResolver
);