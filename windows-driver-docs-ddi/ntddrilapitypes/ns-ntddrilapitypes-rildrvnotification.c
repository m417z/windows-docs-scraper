typedef struct RILDRVNOTIFICATION {
  DWORD   cbSize;
  DWORD   cbSizeNeeded;
  DWORD   dwCode;
  HRESULT hrCmdID;
  DWORD   dwDataSize;
  BYTE    pbData[1];
} RILDRVNOTIFICATION, *LPRILDRVNOTIFICATION;