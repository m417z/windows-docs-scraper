typedef struct _SERVER_TRANSPORT_INFO_1 {
  DWORD  svti1_numberofvcs;
  LMSTR  svti1_transportname;
  LPBYTE svti1_transportaddress;
  DWORD  svti1_transportaddresslength;
  LMSTR  svti1_networkaddress;
  LMSTR  svti1_domain;
} SERVER_TRANSPORT_INFO_1, *PSERVER_TRANSPORT_INFO_1, *LPSERVER_TRANSPORT_INFO_1;