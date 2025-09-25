SECURITY_STATUS SslGetServerIdentity(
  [in]  PBYTE  ClientHello,
  [in]  DWORD  ClientHelloSize,
  [out] PBYTE  *ServerIdentity,
  [out] PDWORD ServerIdentitySize,
  [in]  DWORD  Flags
);