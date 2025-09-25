typedef struct _SERVICE_TYPE_INFO_ABSW {
  LPWSTR                  lpTypeName;
  DWORD                   dwValueCount;
  SERVICE_TYPE_VALUE_ABSW Values[1];
} SERVICE_TYPE_INFO_ABSW, *PSERVICE_TYPE_INFO_ABSW, *LPSERVICE_TYPE_INFO_ABSW;