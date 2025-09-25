typedef struct _SECURITY_STRING {
  unsigned short Length;
  unsigned short MaximumLength;
  unsigned short *Buffer;
} SECURITY_STRING, *PSECURITY_STRING;