typedef struct _AUTHZ_ACCESS_REQUEST {
  ACCESS_MASK       DesiredAccess;
  PSID              PrincipalSelfSid;
  POBJECT_TYPE_LIST ObjectTypeList;
  DWORD             ObjectTypeListLength;
  PVOID             OptionalArguments;
} AUTHZ_ACCESS_REQUEST, *PAUTHZ_ACCESS_REQUEST;