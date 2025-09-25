NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerGroupRegisterEvent(
  [in]  HGROUP                        hGroup,
  [in]  HANDLE                        hEvent,
  [in]  DWORD                         cEventRegistration,
  [in]  PEER_GROUP_EVENT_REGISTRATION *pEventRegistrations,
  [out] HPEEREVENT                    *phPeerEvent
);