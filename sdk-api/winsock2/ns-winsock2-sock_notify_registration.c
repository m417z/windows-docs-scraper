typedef struct SOCK_NOTIFY_REGISTRATION {
  SOCKET socket;
  PVOID  completionKey;
  UINT16 eventFilter;
  UINT8  operation;
  UINT8  triggerFlags;
  DWORD  registrationResult;
} SOCK_NOTIFY_REGISTRATION;