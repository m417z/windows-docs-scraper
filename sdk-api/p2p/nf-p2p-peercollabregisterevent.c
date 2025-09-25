NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerCollabRegisterEvent(
  [in]  HANDLE                         hEvent,
  [in]  DWORD                          cEventRegistration,
  [in]  PEER_COLLAB_EVENT_REGISTRATION *pEventRegistrations,
  [out] HPEEREVENT                     *phPeerEvent
);