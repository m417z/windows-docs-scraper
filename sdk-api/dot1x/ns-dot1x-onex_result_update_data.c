typedef struct _ONEX_RESULT_UPDATE_DATA {
  ONEX_STATUS                     oneXStatus;
  ONEX_EAP_METHOD_BACKEND_SUPPORT BackendSupport;
  BOOL                            fBackendEngaged;
  DWORD                           fOneXAuthParams : 1;
  DWORD                           fEapError : 1;
  ONEX_VARIABLE_BLOB              authParams;
  ONEX_VARIABLE_BLOB              eapError;
} ONEX_RESULT_UPDATE_DATA, *PONEX_RESULT_UPDATE_DATA;