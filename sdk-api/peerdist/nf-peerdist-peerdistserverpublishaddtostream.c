DWORD PeerDistServerPublishAddToStream(
  [in] PEERDIST_INSTANCE_HANDLE hPeerDist,
  [in] PEERDIST_STREAM_HANDLE   hStream,
  [in] DWORD                    cbNumberOfBytes,
  [in] PBYTE                    pBuffer,
  [in] LPOVERLAPPED             lpOverlapped
);