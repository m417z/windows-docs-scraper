typedef struct _RPC_HTTP_TRANSPORT_CREDENTIALS_V3_A {
  RPC_AUTH_IDENTITY_HANDLE TransportCredentials;
  unsigned long            Flags;
  unsigned long            AuthenticationTarget;
  unsigned long            NumberOfAuthnSchemes;
  unsigned long            *AuthnSchemes;
  unsigned char            *ServerCertificateSubject;
  RPC_AUTH_IDENTITY_HANDLE ProxyCredentials;
  unsigned long            NumberOfProxyAuthnSchemes;
  unsigned long            *ProxyAuthnSchemes;
} RPC_HTTP_TRANSPORT_CREDENTIALS_V3_A, *PRPC_HTTP_TRANSPORT_CREDENTIALS_V3_A;