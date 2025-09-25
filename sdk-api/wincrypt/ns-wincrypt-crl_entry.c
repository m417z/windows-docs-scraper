typedef struct _CRL_ENTRY {
  CRYPT_INTEGER_BLOB SerialNumber;
  FILETIME           RevocationDate;
  DWORD              cExtension;
  PCERT_EXTENSION    rgExtension;
} CRL_ENTRY, *PCRL_ENTRY;