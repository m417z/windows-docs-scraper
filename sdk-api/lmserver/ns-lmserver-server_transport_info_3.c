typedef struct _SERVER_TRANSPORT_INFO_3 {
  DWORD  svti3_numberofvcs;
  LMSTR  svti3_transportname;
  LPBYTE svti3_transportaddress;
  DWORD  svti3_transportaddresslength;
  LMSTR  svti3_networkaddress;
  LMSTR  svti3_domain;
  ULONG  svti3_flags;
  DWORD  svti3_passwordlength;
  BYTE   svti3_password[256];
} SERVER_TRANSPORT_INFO_3, *PSERVER_TRANSPORT_INFO_3, *LPSERVER_TRANSPORT_INFO_3;