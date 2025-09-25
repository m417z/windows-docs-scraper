typedef struct _RPC_HTTP_TRANSPORT_CREDENTIALS_W {
  SEC_WINNT_AUTH_IDENTITY_W *TransportCredentials;
  unsigned long             Flags;
  unsigned long             AuthenticationTarget;
  unsigned long             NumberOfAuthnSchemes;
  unsigned long             *AuthnSchemes;
  unsigned short            *ServerCertificateSubject;
} RPC_HTTP_TRANSPORT_CREDENTIALS_W, *PRPC_HTTP_TRANSPORT_CREDENTIALS_W;