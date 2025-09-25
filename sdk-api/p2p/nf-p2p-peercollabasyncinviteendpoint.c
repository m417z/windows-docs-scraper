NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerCollabAsyncInviteEndpoint(
  [in]            PCPEER_ENDPOINT   pcEndpoint,
  [in]            PCPEER_INVITATION pcInvitation,
  [in, optional]  HANDLE            hEvent,
  [out, optional] HANDLE            *phInvitation
);