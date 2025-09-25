typedef struct _ONEX_STATUS {
  ONEX_AUTH_STATUS authStatus;
  DWORD            dwReason;
  DWORD            dwError;
} ONEX_STATUS, *PONEX_STATUS;