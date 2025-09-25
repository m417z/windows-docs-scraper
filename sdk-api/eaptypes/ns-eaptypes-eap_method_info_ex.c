typedef struct _EAP_METHOD_INFO_EX {
  EAP_METHOD_TYPE                  eaptype;
  LPWSTR                           pwszAuthorName;
  LPWSTR                           pwszFriendlyName;
  DWORD                            eapProperties;
  struct _EAP_METHOD_INFO_ARRAY_EX *pInnerMethodInfoArray;
} EAP_METHOD_INFO_EX;