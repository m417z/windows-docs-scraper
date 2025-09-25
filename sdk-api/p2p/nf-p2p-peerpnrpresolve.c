NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerPnrpResolve(
  [in]           PCWSTR                   pcwzPeerName,
  [in, optional] PCWSTR                   pcwzCloudName,
  [in, out]      ULONG                    *pcEndpoints,
  [out]          PPEER_PNRP_ENDPOINT_INFO *ppEndpoints
);