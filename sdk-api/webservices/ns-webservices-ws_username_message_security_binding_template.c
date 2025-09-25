typedef struct _WS_USERNAME_MESSAGE_SECURITY_BINDING_TEMPLATE {
  WS_SECURITY_BINDING_PROPERTIES securityBindingProperties;
  WS_USERNAME_CREDENTIAL         *clientCredential;
  WS_VALIDATE_PASSWORD_CALLBACK  passwordValidator;
  void                           *passwordValidatorCallbackState;
} WS_USERNAME_MESSAGE_SECURITY_BINDING_TEMPLATE;