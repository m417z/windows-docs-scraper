HRESULT FilterGetMessage(
  [in]      HANDLE                 hPort,
  [out]     PFILTER_MESSAGE_HEADER lpMessageBuffer,
  [in]      DWORD                  dwMessageBufferSize,
  [in, out] LPOVERLAPPED           lpOverlapped
);