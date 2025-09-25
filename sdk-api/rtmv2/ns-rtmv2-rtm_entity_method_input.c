typedef struct _RTM_ENTITY_METHOD_INPUT {
  RTM_ENTITY_METHOD_TYPE MethodType;
  UINT                   InputSize;
  UCHAR                  InputData[1];
} RTM_ENTITY_METHOD_INPUT, *PRTM_ENTITY_METHOD_INPUT;