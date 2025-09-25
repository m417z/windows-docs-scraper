typedef struct _SEC_WINNT_CREDUI_CONTEXT {
  USHORT                          cbHeaderLength;
  HANDLE                          CredUIContextHandle;
#if ...
  PCREDUI_INFOW                   UIInfo;
#else
  PVOID                           UIInfo;
#endif
  ULONG                           dwAuthError;
  PSEC_WINNT_AUTH_IDENTITY_OPAQUE pInputAuthIdentity;
  PUNICODE_STRING                 TargetName;
} SEC_WINNT_CREDUI_CONTEXT, *PSEC_WINNT_CREDUI_CONTEXT;