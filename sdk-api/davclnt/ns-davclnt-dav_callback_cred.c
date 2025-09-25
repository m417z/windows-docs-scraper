typedef struct _DAV_CALLBACK_CRED {
  DAV_CALLBACK_AUTH_BLOB AuthBlob;
  DAV_CALLBACK_AUTH_UNP  UNPBlob;
  BOOL                   bAuthBlobValid;
  BOOL                   bSave;
} DAV_CALLBACK_CRED, *PDAV_CALLBACK_CRED;