INT WSAAPI WSADeleteSocketPeerTargetName(
  [in]           SOCKET                             Socket,
  [in]           const sockaddr                     *PeerAddr,
  [in]           ULONG                              PeerAddrLen,
  [in, optional] LPWSAOVERLAPPED                    Overlapped,
  [in, optional] LPWSAOVERLAPPED_COMPLETION_ROUTINE CompletionRoutine
);