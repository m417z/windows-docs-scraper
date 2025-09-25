DWORD PeerDistServerPublishStream(
  [in]           PEERDIST_INSTANCE_HANDLE       hPeerDist,
                 DWORD                          cbContentIdentifier,
  [in]           PBYTE                          pContentIdentifier,
                 ULONGLONG                      cbContentLength,
  [in, optional] PCPEERDIST_PUBLICATION_OPTIONS pPublishOptions,
  [in, optional] HANDLE                         hCompletionPort,
  [in, optional] ULONG_PTR                      ulCompletionKey,
  [out]          PPEERDIST_STREAM_HANDLE        phStream
);