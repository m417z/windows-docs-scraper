BOOL TransmitFile(
  SOCKET                  hSocket,
  HANDLE                  hFile,
  DWORD                   nNumberOfBytesToWrite,
  DWORD                   nNumberOfBytesPerSend,
  LPOVERLAPPED            lpOverlapped,
  LPTRANSMIT_FILE_BUFFERS lpTransmitBuffers,
  DWORD                   dwReserved
);