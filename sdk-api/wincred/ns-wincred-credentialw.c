typedef struct _CREDENTIALW {
  DWORD                  Flags;
  DWORD                  Type;
#if ...
  wchar_t                *TargetName;
#else
  LPWSTR                 TargetName;
#endif
#if ...
  wchar_t                *Comment;
#else
  LPWSTR                 Comment;
#endif
  FILETIME               LastWritten;
  DWORD                  CredentialBlobSize;
  LPBYTE                 CredentialBlob;
  DWORD                  Persist;
  DWORD                  AttributeCount;
  PCREDENTIAL_ATTRIBUTEW Attributes;
#if ...
  wchar_t                *TargetAlias;
#else
  LPWSTR                 TargetAlias;
#endif
#if ...
  wchar_t                *UserName;
#else
  LPWSTR                 UserName;
#endif
} CREDENTIALW, *PCREDENTIALW;