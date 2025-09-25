typedef struct _RAS_AUTH_ATTRIBUTE {
  RAS_AUTH_ATTRIBUTE_TYPE raaType;
  DWORD                   dwLength;
  PVOID                   Value;
} RAS_AUTH_ATTRIBUTE, *PRAS_AUTH_ATTRIBUTE;