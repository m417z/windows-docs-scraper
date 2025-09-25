typedef struct _KERB_S4U_LOGON {
  KERB_LOGON_SUBMIT_TYPE MessageType;
  ULONG                  Flags;
  UNICODE_STRING         ClientUpn;
  UNICODE_STRING         ClientRealm;
} KERB_S4U_LOGON, *PKERB_S4U_LOGON;