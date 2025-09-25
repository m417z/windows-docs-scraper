typedef struct _RTM_ENTITY_METHOD_OUTPUT {
  RTM_ENTITY_METHOD_TYPE MethodType;
  DWORD                  MethodStatus;
  UINT                   OutputSize;
  UCHAR                  OutputData[1];
} RTM_ENTITY_METHOD_OUTPUT, *PRTM_ENTITY_METHOD_OUTPUT;