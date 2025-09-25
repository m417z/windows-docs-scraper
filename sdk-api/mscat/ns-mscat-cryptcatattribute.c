typedef struct CRYPTCATATTRIBUTE_ {
  DWORD  cbStruct;
  LPWSTR pwszReferenceTag;
  DWORD  dwAttrTypeAndAction;
  DWORD  cbValue;
  BYTE   *pbValue;
  DWORD  dwReserved;
} CRYPTCATATTRIBUTE;