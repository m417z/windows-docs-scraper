typedef struct _RPC_HTTP_TRANSPORT_CREDENTIALS_A {
  SEC_WINNT_AUTH_IDENTITY_A *TransportCredentials;
  unsigned long             Flags;
  unsigned long             AuthenticationTarget;
  unsigned long             NumberOfAuthnSchemes;
  unsigned long             *AuthnSchemes;
  unsigned char             *ServerCertificateSubject;
} RPC_HTTP_TRANSPORT_CREDENTIALS_A, *PRPC_HTTP_TRANSPORT_CREDENTIALS_A;