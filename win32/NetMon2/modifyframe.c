HFRAME WINAPI ModifyFrame(
  _In_  HCAPTURE hCapture,
  _In_  DWORD    FrameNumber,
  _In_  LPBYTE   FrameData,
  _In_  DWORD    FrameLength,
  _Out_ __int64  TimeStamp
);