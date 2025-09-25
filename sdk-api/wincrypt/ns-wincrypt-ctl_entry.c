typedef struct _CTL_ENTRY {
  CRYPT_DATA_BLOB  SubjectIdentifier;
  DWORD            cAttribute;
  PCRYPT_ATTRIBUTE rgAttribute;
} CTL_ENTRY, *PCTL_ENTRY;