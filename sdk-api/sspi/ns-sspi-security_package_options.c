typedef struct _SECURITY_PACKAGE_OPTIONS {
  unsigned long Size;
  unsigned long Type;
  unsigned long Flags;
  unsigned long SignatureSize;
  void          *Signature;
} SECURITY_PACKAGE_OPTIONS, *PSECURITY_PACKAGE_OPTIONS;