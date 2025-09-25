typedef struct tagMFASYNCRESULT : IMFAsyncResult {
  OVERLAPPED       overlapped;
  IMFAsyncCallback *pCallback;
  HRESULT          hrStatusResult;
  DWORD            dwBytesTransferred;
  HANDLE           hEvent;
} MFASYNCRESULT;