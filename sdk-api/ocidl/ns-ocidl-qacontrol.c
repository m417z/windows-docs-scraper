typedef struct tagQACONTROL {
  ULONG cbSize;
  DWORD dwMiscStatus;
  DWORD dwViewStatus;
  DWORD dwEventCookie;
  DWORD dwPropNotifyCookie;
  DWORD dwPointerActivationPolicy;
} QACONTROL;