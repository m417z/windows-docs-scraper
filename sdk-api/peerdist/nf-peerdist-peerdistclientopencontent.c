DWORD PeerDistClientOpenContent(
  [in]           PEERDIST_INSTANCE_HANDLE hPeerDist,
  [in]           PCPEERDIST_CONTENT_TAG   pContentTag,
  [in, optional] HANDLE                   hCompletionPort,
  [in, optional] ULONG_PTR                ulCompletionKey,
  [out]          PPEERDIST_CONTENT_HANDLE phContentHandle
);