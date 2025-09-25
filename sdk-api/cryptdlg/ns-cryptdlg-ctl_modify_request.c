typedef struct _CTL_MODIFY_REQUEST {
  PCCERT_CONTEXT pccert;
  DWORD          dwOperation;
  DWORD          dwError;
} CTL_MODIFY_REQUEST, *PCTL_MODIFY_REQUEST;