typedef struct _SE_TOKEN_USER {
  union {
    TOKEN_USER         TokenUser;
    SID_AND_ATTRIBUTES User;
  } DUMMYUNIONNAME;
  union {
    SID   Sid;
    UCHAR Buffer[SECURITY_MAX_SID_SIZE];
  } DUMMYUNIONNAME2;
} SE_TOKEN_USER, PSE_TOKEN_USER;