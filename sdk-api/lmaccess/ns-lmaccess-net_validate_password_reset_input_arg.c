typedef struct _NET_VALIDATE_PASSWORD_RESET_INPUT_ARG {
  NET_VALIDATE_PERSISTED_FIELDS InputPersistedFields;
  LPWSTR                        ClearPassword;
  LPWSTR                        UserAccountName;
  NET_VALIDATE_PASSWORD_HASH    HashedPassword;
  BOOLEAN                       PasswordMustChangeAtNextLogon;
  BOOLEAN                       ClearLockout;
} NET_VALIDATE_PASSWORD_RESET_INPUT_ARG, *PNET_VALIDATE_PASSWORD_RESET_INPUT_ARG;