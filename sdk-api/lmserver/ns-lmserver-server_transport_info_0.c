typedef struct _SERVER_TRANSPORT_INFO_0 {
  DWORD  svti0_numberofvcs;
  LMSTR  svti0_transportname;
  LPBYTE svti0_transportaddress;
  DWORD  svti0_transportaddresslength;
  LMSTR  svti0_networkaddress;
} SERVER_TRANSPORT_INFO_0, *PSERVER_TRANSPORT_INFO_0, *LPSERVER_TRANSPORT_INFO_0;