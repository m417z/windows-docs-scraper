typedef struct __MIDL___MIDL_itf_autosvcs_0000_0013_0001 {
  DWORD    cbSize;
  DWORD    dwPid;
  LONGLONG lTime;
  LONG     lMicroTime;
  LONGLONG perfCount;
  GUID     guidApp;
  LPOLESTR sMachineName;
} COMSVCSEVENTINFO;