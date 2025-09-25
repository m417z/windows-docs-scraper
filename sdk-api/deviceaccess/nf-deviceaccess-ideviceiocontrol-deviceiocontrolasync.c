HRESULT DeviceIoControlAsync(
  [in]  DWORD                            ioControlCode,
  [in]  UCHAR                            *inputBuffer,
  [in]  DWORD                            inputBufferSize,
  [out] UCHAR                            *outputBuffer,
  [in]  DWORD                            outputBufferSize,
  [in]  IDeviceRequestCompletionCallback *requestCompletionCallback,
  [out] ULONG_PTR                        *cancelContext
);