typedef struct _SEC_TOKEN_BINDING {
  unsigned char  MajorVersion;
  unsigned char  MinorVersion;
  unsigned short KeyParametersSize;
  unsigned char  KeyParameters[ANYSIZE_ARRAY];
} SEC_TOKEN_BINDING, *PSEC_TOKEN_BINDING;