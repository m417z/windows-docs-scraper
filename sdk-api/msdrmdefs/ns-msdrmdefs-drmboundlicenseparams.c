typedef struct _DRMBOUNDLICENSEPARAMS {
  UINT      uVersion;
  DRMHANDLE hEnablingPrincipal;
  DRMHANDLE hSecureStore;
  PWSTR     wszRightsRequested;
  PWSTR     wszRightsGroup;
  DRMID     idResource;
  UINT      cAuthenticatorCount;
  DRMHANDLE *rghAuthenticators;
  PWSTR     wszDefaultEnablingPrincipalCredentials;
  DWORD     dwFlags;
  void      _DRMBOUNDLICENSEPARAMS();
} DRMBOUNDLICENSEPARAMS;