typedef struct _EAP_METHOD_PROPERTY_VALUE_STRING {
  DWORD length;
#if ...
  BYTE  *value;
#else
  BYTE  *value;
#endif
} EAP_METHOD_PROPERTY_VALUE_STRING;