typedef struct _RAS_USER_0 {
  BYTE  bfPrivilege;
  WCHAR wszPhoneNumber[MAX_PHONE_NUMBER_LEN + 1];
} RAS_USER_0, *PRAS_USER_0;