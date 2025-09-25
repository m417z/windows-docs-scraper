DWORD PeerDistRegisterForStatusChangeNotification(
  [in]           PEERDIST_INSTANCE_HANDLE hPeerDist,
  [in, optional] HANDLE                   hCompletionPort,
  [in, optional] ULONG_PTR                ulCompletionKey,
  [in]           LPOVERLAPPED             lpOverlapped,
  [out]          PEERDIST_STATUS          *pPeerDistStatus
);