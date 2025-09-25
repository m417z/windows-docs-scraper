NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerPnrpStartResolve(
  [in]           PCWSTR      pcwzPeerName,
  [in, optional] PCWSTR      pcwzCloudName,
  [in, optional] ULONG       cMaxEndpoints,
  [in]           HANDLE      hEvent,
  [out]          HRESOLUTION *phResolve
);