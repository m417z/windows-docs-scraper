typedef struct _AUTHZ_SECURITY_ATTRIBUTE_V1 {
  PWSTR  pName;
  USHORT ValueType;
  USHORT Reserved;
  ULONG  Flags;
  ULONG  ValueCount;
  union {
    PLONG64                                      pInt64;
    PULONG64                                     pUint64;
    PWSTR                                        *ppString;
    PAUTHZ_SECURITY_ATTRIBUTE_FQBN_VALUE         pFqbn;
    PAUTHZ_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE pOctetString;
  } Values;
} AUTHZ_SECURITY_ATTRIBUTE_V1, *PAUTHZ_SECURITY_ATTRIBUTE_V1;