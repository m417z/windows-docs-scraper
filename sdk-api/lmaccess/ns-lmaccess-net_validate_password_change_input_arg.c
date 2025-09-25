typedef struct _NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG {
  NET_VALIDATE_PERSISTED_FIELDS InputPersistedFields;
  LPWSTR                        ClearPassword;
  LPWSTR                        UserAccountName;
  NET_VALIDATE_PASSWORD_HASH    HashedPassword;
  BOOLEAN                       PasswordMatch;
} NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG, *PNET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG;