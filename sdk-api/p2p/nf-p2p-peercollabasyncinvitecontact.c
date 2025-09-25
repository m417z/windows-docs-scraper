NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerCollabAsyncInviteContact(
  [in, optional] PCPEER_CONTACT    pcContact,
  [in]           PCPEER_ENDPOINT   pcEndpoint,
  [in]           PCPEER_INVITATION pcInvitation,
  [in, optional] HANDLE            hEvent,
  [optional]     HANDLE            *phInvitation
);