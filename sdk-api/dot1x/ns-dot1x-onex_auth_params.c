typedef struct _ONEX_AUTH_PARAMS {
  BOOL               fUpdatePending;
  ONEX_VARIABLE_BLOB oneXConnProfile;
  ONEX_AUTH_IDENTITY authIdentity;
  DWORD              dwQuarantineState;
  DWORD              fSessionId : 1;
  DWORD              fhUserToken : 1;
  DWORD              fOnexUserProfile : 1;
  DWORD              fIdentity : 1;
  DWORD              fUserName : 1;
  DWORD              fDomain : 1;
  DWORD              dwSessionId;
  HANDLE             hUserToken;
  ONEX_VARIABLE_BLOB OneXUserProfile;
  ONEX_VARIABLE_BLOB Identity;
  ONEX_VARIABLE_BLOB UserName;
  ONEX_VARIABLE_BLOB Domain;
} ONEX_AUTH_PARAMS, *PONEX_AUTH_PARAMS;