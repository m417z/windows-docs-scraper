typedef struct _CTL_INFO {
  DWORD                      dwVersion;
  CTL_USAGE                  SubjectUsage;
  CRYPT_DATA_BLOB            ListIdentifier;
  CRYPT_INTEGER_BLOB         SequenceNumber;
  FILETIME                   ThisUpdate;
  FILETIME                   NextUpdate;
  CRYPT_ALGORITHM_IDENTIFIER SubjectAlgorithm;
  DWORD                      cCTLEntry;
  PCTL_ENTRY                 rgCTLEntry;
  DWORD                      cExtension;
  PCERT_EXTENSION            rgExtension;
} CTL_INFO, *PCTL_INFO;