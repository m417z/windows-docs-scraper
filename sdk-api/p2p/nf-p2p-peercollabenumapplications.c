NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerCollabEnumApplications(
  [in, optional] PCPEER_ENDPOINT pcEndpoint,
  [in, optional] const GUID      *pApplicationId,
  [out]          HPEERENUM       *phPeerEnum
);