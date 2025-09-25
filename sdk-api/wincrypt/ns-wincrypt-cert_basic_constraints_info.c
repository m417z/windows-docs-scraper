typedef struct _CERT_BASIC_CONSTRAINTS_INFO {
  CRYPT_BIT_BLOB SubjectType;
  BOOL           fPathLenConstraint;
  DWORD          dwPathLenConstraint;
  DWORD          cSubtreesConstraint;
  CERT_NAME_BLOB *rgSubtreesConstraint;
} CERT_BASIC_CONSTRAINTS_INFO, *PCERT_BASIC_CONSTRAINTS_INFO;