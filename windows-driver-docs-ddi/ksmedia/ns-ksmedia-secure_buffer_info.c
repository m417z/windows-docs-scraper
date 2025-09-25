typedef struct {
  GUID      guidBufferIdentifier;
  DWORD     cbBufferSize;
  DWORD     cbCaptured;
  ULONGLONG ullReserved[16];
} SECURE_BUFFER_INFO, *PSECURE_BUFFER_INFO;