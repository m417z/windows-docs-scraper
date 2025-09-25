NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerGraphRegisterEvent(
  [in]  HGRAPH                        hGraph,
  [in]  HANDLE                        hEvent,
  [in]  ULONG                         cEventRegistrations,
  [in]  PEER_GRAPH_EVENT_REGISTRATION *pEventRegistrations,
  [out] HPEEREVENT                    *phPeerEvent
);