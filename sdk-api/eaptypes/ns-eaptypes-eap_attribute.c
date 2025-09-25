typedef struct _EAP_ATTRIBUTE {
  EAP_ATTRIBUTE_TYPE eaType;
  DWORD              dwLength;
#if ...
  BYTE               *pValue;
#else
  BYTE               *pValue;
#endif
} EAP_ATTRIBUTE, EapAttribute;