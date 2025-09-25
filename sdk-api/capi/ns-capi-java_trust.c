typedef struct _JAVA_TRUST {
  DWORD   cbSize;
  DWORD   flag;
  BOOL    fAllActiveXPermissions;
  BOOL    fAllPermissions;
  DWORD   dwEncodingType;
  PBYTE   pbJavaPermissions;
  DWORD   cbJavaPermissions;
  PBYTE   pbSigner;
  DWORD   cbSigner;
  LPCWSTR pwszZone;
  GUID    guidZone;
  HRESULT hVerify;
} JAVA_TRUST, *PJAVA_TRUST;