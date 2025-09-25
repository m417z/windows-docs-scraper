DWORD PeerDistClientGetInformationByHandle(
  [in]  PEERDIST_INSTANCE_HANDLE             hPeerDist,
  [in]  PEERDIST_CONTENT_HANDLE              hContentHandle,
  [in]  PEERDIST_CLIENT_INFO_BY_HANDLE_CLASS PeerDistClientInfoClass,
        DWORD                                dwBufferSize,
  [out] LPVOID                               lpInformation
);