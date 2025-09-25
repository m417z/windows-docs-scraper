int WPUCompleteOverlappedRequest(
  [in]  SOCKET          s,
  [in]  LPWSAOVERLAPPED lpOverlapped,
  [in]  DWORD           dwError,
  [in]  DWORD           cbTransferred,
  [out] LPINT           lpErrno
);