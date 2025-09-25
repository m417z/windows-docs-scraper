typedef union {
  EAP_CRED_REQ        *credData;
  EAP_CRED_EXPIRY_REQ *credExpiryData;
  EAP_CRED_LOGON_REQ  *credLogonData;
} EAP_UI_DATA_FORMAT;