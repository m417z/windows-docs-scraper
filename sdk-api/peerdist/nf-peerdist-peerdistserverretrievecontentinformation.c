DWORD PeerDistServerRetrieveContentInformation(
  [in]      PEERDIST_INSTANCE_HANDLE    hPeerDist,
  [in]      PEERDIST_CONTENTINFO_HANDLE hContentInfo,
            DWORD                       cbMaxNumberOfBytes,
  [in, out] PBYTE                       pBuffer,
  [in]      LPOVERLAPPED                lpOverlapped
);