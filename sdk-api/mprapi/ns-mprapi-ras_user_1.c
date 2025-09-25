typedef struct _RAS_USER_1 {
  BYTE  bfPrivilege;
  WCHAR wszPhoneNumber[MAX_PHONE_NUMBER_LEN + 1];
  BYTE  bfPrivilege2;
} RAS_USER_1, *PRAS_USER_1;