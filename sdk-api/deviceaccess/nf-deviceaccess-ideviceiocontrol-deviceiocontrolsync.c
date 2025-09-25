HRESULT DeviceIoControlSync(
  [in]  DWORD ioControlCode,
  [in]  UCHAR *inputBuffer,
  [in]  DWORD inputBufferSize,
  [out] UCHAR *outputBuffer,
  [in]  DWORD outputBufferSize,
  [out] DWORD *bytesReturned
);