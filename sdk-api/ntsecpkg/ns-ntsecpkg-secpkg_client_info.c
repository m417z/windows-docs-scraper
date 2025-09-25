typedef struct _SECPKG_CLIENT_INFO {
  LUID                         LogonId;
  ULONG                        ProcessID;
  ULONG                        ThreadID;
  BOOLEAN                      HasTcbPrivilege;
  BOOLEAN                      Impersonating;
  BOOLEAN                      Restricted;
  UCHAR                        ClientFlags;
  SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
  HANDLE                       ClientToken;
} SECPKG_CLIENT_INFO, *PSECPKG_CLIENT_INFO;