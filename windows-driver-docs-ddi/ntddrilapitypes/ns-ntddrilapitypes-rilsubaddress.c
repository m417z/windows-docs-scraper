typedef struct RILSUBADDRESS {
  DWORD             cbSize;
  DWORD             dwParams;
  RILSUBADDRESSTYPE dwType;
  WCHAR             wszSubAddress[256];
} RILSUBADDRESS, *LPRILSUBADDRESS;