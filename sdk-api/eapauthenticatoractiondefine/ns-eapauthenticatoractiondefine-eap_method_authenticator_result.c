typedef struct _EAP_METHOD_AUTHENTICATOR_RESULT {
  BOOL           fIsSuccess;
  DWORD          dwFailureReason;
  EAP_ATTRIBUTES *pAuthAttribs;
} EAP_METHOD_AUTHENTICATOR_RESULT;