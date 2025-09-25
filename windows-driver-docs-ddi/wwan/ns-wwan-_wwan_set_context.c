typedef struct _WWAN_SET_CONTEXT {
  ULONG              ContextId;
  WWAN_CONTEXT_TYPE  ContextType;
  WCHAR              AccessString[WWAN_ACCESSSTRING_LEN];
  WCHAR              UserName[WWAN_USERNAME_LEN];
  WCHAR              Password[WWAN_PASSWORD_LEN];
  WWAN_COMPRESSION   Compression;
  WWAN_AUTH_PROTOCOL AuthType;
  WCHAR              ProviderId[WWAN_PROVIDERID_LEN];
} WWAN_SET_CONTEXT, *PWWAN_SET_CONTEXT;