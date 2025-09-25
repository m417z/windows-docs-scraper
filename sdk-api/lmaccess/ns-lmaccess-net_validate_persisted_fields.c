typedef struct _NET_VALIDATE_PERSISTED_FIELDS {
  ULONG                       PresentFields;
  FILETIME                    PasswordLastSet;
  FILETIME                    BadPasswordTime;
  FILETIME                    LockoutTime;
  ULONG                       BadPasswordCount;
  ULONG                       PasswordHistoryLength;
  PNET_VALIDATE_PASSWORD_HASH PasswordHistory;
} NET_VALIDATE_PERSISTED_FIELDS, *PNET_VALIDATE_PERSISTED_FIELDS;