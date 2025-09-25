typedef struct RILIMSFAILURE {
  DWORD                    cbSize;
  DWORD                    dwParams;
  DWORD                    dwExecutor;
  RILIMSFAILUREMESSAGETYPE dwMessageType;
  DWORD                    dwMessageSubType;
  DWORD                    dwErrorCode;
  WCHAR                    wszErrorString[256];
} RILIMSFAILURE, *LPRILIMSFAILURE;