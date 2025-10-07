typedef struct _HS_SIM_IDENTITY {
  eHS_SIM_TYPE SimType;
  DWORD        dwMNC;
  DWORD        dwMCC;
  DWORD        dwNID;
  DWORD        dwSID;
  DWORD        dwEapMethods;
} HS_SIM_IDENTITY, *PHS_SIM_IDENTITY;