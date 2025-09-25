typedef struct IKEEXT_AUTHENTICATION_METHOD1_ {
  IKEEXT_AUTHENTICATION_METHOD_TYPE authenticationMethodType;
  union {
    IKEEXT_PRESHARED_KEY_AUTHENTICATION1 presharedKeyAuthentication;
    IKEEXT_CERTIFICATE_AUTHENTICATION1   certificateAuthentication;
    IKEEXT_KERBEROS_AUTHENTICATION0      kerberosAuthentication;
    IKEEXT_NTLM_V2_AUTHENTICATION0       ntlmV2Authentication;
    IKEEXT_CERTIFICATE_AUTHENTICATION1   sslAuthentication;
    IKEEXT_IPV6_CGA_AUTHENTICATION0      cgaAuthentication;
    IKEEXT_EAP_AUTHENTICATION0           eapAuthentication;
  };
} IKEEXT_AUTHENTICATION_METHOD1;