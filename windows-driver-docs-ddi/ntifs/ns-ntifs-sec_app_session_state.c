typedef struct _SEC_APP_SESSION_STATE {
  unsigned short AppSessionStateSize;
  unsigned char  AppSessionState[ANYSIZE_ARRAY];
} SEC_APP_SESSION_STATE, *PSEC_APP_SESSION_STATE;