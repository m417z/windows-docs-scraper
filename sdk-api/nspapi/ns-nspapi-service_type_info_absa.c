typedef struct _SERVICE_TYPE_INFO_ABSA {
  LPSTR                   lpTypeName;
  DWORD                   dwValueCount;
  SERVICE_TYPE_VALUE_ABSA Values[1];
} SERVICE_TYPE_INFO_ABSA, *PSERVICE_TYPE_INFO_ABSA, *LPSERVICE_TYPE_INFO_ABSA;