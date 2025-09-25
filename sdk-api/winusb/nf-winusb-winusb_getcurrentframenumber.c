BOOL WinUsb_GetCurrentFrameNumber(
  [in]  WINUSB_INTERFACE_HANDLE InterfaceHandle,
  [out] PULONG                  CurrentFrameNumber,
  [out] LARGE_INTEGER           *TimeStamp
);