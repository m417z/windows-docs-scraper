typedef struct _HTTP_REQUEST_AUTH_INFO {
  HTTP_AUTH_STATUS       AuthStatus;
  SECURITY_STATUS        SecStatus;
  ULONG                  Flags;
  HTTP_REQUEST_AUTH_TYPE AuthType;
  HANDLE                 AccessToken;
  ULONG                  ContextAttributes;
  ULONG                  PackedContextLength;
  ULONG                  PackedContextType;
  PVOID                  PackedContext;
  ULONG                  MutualAuthDataLength;
  PCHAR                  pMutualAuthData;
  USHORT                 PackageNameLength;
  PWSTR                  pPackageName;
} HTTP_REQUEST_AUTH_INFO, *PHTTP_REQUEST_AUTH_INFO;