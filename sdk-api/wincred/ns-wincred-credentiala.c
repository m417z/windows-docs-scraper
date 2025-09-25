typedef struct _CREDENTIALA {
  DWORD                  Flags;
  DWORD                  Type;
  LPSTR                  TargetName;
  LPSTR                  Comment;
  FILETIME               LastWritten;
  DWORD                  CredentialBlobSize;
  LPBYTE                 CredentialBlob;
  DWORD                  Persist;
  DWORD                  AttributeCount;
  PCREDENTIAL_ATTRIBUTEA Attributes;
  LPSTR                  TargetAlias;
  LPSTR                  UserName;
} CREDENTIALA, *PCREDENTIALA;