typedef struct _SECPKG_CREDENTIAL {
  ULONG64            Version;
  USHORT             cbHeaderLength;
  ULONG              cbStructureLength;
  ULONG              ClientProcess;
  ULONG              ClientThread;
  LUID               LogonId;
  HANDLE             ClientToken;
  ULONG              SessionId;
  LUID               ModifiedId;
  ULONG              fCredentials;
  ULONG              Flags;
  SECPKG_BYTE_VECTOR PrincipalName;
  SECPKG_BYTE_VECTOR PackageList;
  SECPKG_BYTE_VECTOR MarshaledSuppliedCreds;
} SECPKG_CREDENTIAL, *PSECPKG_CREDENTIAL;