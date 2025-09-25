DWORD PeerDistServerOpenContentInformation(
  [in]           PEERDIST_INSTANCE_HANDLE     hPeerDist,
                 DWORD                        cbContentIdentifier,
  [in]           PBYTE                        pContentIdentifier,
                 ULONGLONG                    ullContentOffset,
                 ULONGLONG                    cbContentLength,
  [in, optional] HANDLE                       hCompletionPort,
  [in, optional] ULONG_PTR                    ulCompletionKey,
  [out]          PPEERDIST_CONTENTINFO_HANDLE phContentInfo
);