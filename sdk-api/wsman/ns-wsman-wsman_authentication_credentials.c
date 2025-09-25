typedef struct _WSMAN_AUTHENTICATION_CREDENTIALS {
  DWORD authenticationMechanism;
  union {
    WSMAN_USERNAME_PASSWORD_CREDS userAccount;
    PCWSTR                        certificateThumbprint;
  };
} WSMAN_AUTHENTICATION_CREDENTIALS;