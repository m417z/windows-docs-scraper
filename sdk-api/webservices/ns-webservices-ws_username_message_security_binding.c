typedef struct _WS_USERNAME_MESSAGE_SECURITY_BINDING {
  WS_SECURITY_BINDING           binding;
  WS_MESSAGE_SECURITY_USAGE     bindingUsage;
  WS_USERNAME_CREDENTIAL        *clientCredential;
  WS_VALIDATE_PASSWORD_CALLBACK passwordValidator;
  void                          *passwordValidatorCallbackState;
} WS_USERNAME_MESSAGE_SECURITY_BINDING;