INT WSAAPI WSAImpersonateSocketPeer(
  [in]           SOCKET         Socket,
  [in, optional] const sockaddr *PeerAddr,
  [in]           ULONG          PeerAddrLen
);