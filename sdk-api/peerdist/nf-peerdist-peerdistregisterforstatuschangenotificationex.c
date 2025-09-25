DWORD PeerDistRegisterForStatusChangeNotificationEx(
  [in]           PEERDIST_INSTANCE_HANDLE hPeerDist,
  [in, optional] HANDLE                   hCompletionPort,
  [in, optional] ULONG_PTR                ulCompletionKey,
  [in]           LPOVERLAPPED             lpOverlapped,
  [in, out]      PEERDIST_STATUS_INFO     *pPeerDistStatus
);