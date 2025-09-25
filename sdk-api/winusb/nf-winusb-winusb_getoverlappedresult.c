BOOL WinUsb_GetOverlappedResult(
  [in]  WINUSB_INTERFACE_HANDLE InterfaceHandle,
  [in]  LPOVERLAPPED            lpOverlapped,
  [out] LPDWORD                 lpNumberOfBytesTransferred,
  [in]  BOOL                    bWait
);