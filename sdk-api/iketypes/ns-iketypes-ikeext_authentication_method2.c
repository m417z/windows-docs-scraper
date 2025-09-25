typedef struct IKEEXT_AUTHENTICATION_METHOD2_ {
  IKEEXT_AUTHENTICATION_METHOD_TYPE authenticationMethodType;
  union {
    IKEEXT_PRESHARED_KEY_AUTHENTICATION1 presharedKeyAuthentication;
    IKEEXT_CERTIFICATE_AUTHENTICATION2   certificateAuthentication;
    IKEEXT_KERBEROS_AUTHENTICATION1      kerberosAuthentication;
    IKEEXT_RESERVED_AUTHENTICATION0      reservedAuthentication;
    IKEEXT_NTLM_V2_AUTHENTICATION0       ntlmV2Authentication;
    IKEEXT_CERTIFICATE_AUTHENTICATION2   sslAuthentication;
    IKEEXT_IPV6_CGA_AUTHENTICATION0      cgaAuthentication;
    IKEEXT_EAP_AUTHENTICATION0           eapAuthentication;
  };
} IKEEXT_AUTHENTICATION_METHOD2;