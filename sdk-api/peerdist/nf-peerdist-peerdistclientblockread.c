DWORD PeerDistClientBlockRead(
  [in]                PEERDIST_INSTANCE_HANDLE hPeerDist,
  [in]                PEERDIST_CONTENT_HANDLE  hContentHandle,
                      DWORD                    cbMaxNumberOfBytes,
  [in, out, optional] PBYTE                    pBuffer,
                      DWORD                    dwTimeoutInMilliseconds,
  [in]                LPOVERLAPPED             lpOverlapped
);