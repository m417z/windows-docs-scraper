typedef struct _EAP_METHOD_INFO {
  EAP_METHOD_TYPE         eaptype;
  LPWSTR                  pwszAuthorName;
  LPWSTR                  pwszFriendlyName;
  DWORD                   eapProperties;
  struct _EAP_METHOD_INFO *pInnerMethodInfo;
} EAP_METHOD_INFO;