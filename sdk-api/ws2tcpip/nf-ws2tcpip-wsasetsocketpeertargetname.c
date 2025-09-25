INT WSAAPI WSASetSocketPeerTargetName(
  [in]           SOCKET                             Socket,
  [in]           const SOCKET_PEER_TARGET_NAME      *PeerTargetName,
  [in]           ULONG                              PeerTargetNameLen,
  [in, optional] LPWSAOVERLAPPED                    Overlapped,
  [in, optional] LPWSAOVERLAPPED_COMPLETION_ROUTINE CompletionRoutine
);