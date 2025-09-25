typedef struct _EapCredential {
  EapCredentialType     credType;
#if ...
  EapCredentialTypeData credData;
#else
  EapCredentialTypeData credData;
#endif
} EapCredential;