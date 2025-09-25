typedef struct _SERVER_TRANSPORT_INFO_2 {
  DWORD  svti2_numberofvcs;
  LMSTR  svti2_transportname;
  LPBYTE svti2_transportaddress;
  DWORD  svti2_transportaddresslength;
  LMSTR  svti2_networkaddress;
  LMSTR  svti2_domain;
  ULONG  svti2_flags;
} SERVER_TRANSPORT_INFO_2, *PSERVER_TRANSPORT_INFO_2, *LPSERVER_TRANSPORT_INFO_2;