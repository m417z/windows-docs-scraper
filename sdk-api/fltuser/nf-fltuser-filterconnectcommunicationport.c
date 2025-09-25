HRESULT FilterConnectCommunicationPort(
  [in]           LPCWSTR               lpPortName,
  [in]           DWORD                 dwOptions,
  [in, optional] LPCVOID               lpContext,
  [in]           WORD                  wSizeOfContext,
  [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [out]          HANDLE                *hPort
);