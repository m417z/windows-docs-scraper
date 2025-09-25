typedef struct berval {
  ULONG bv_len;
  PCHAR bv_val;
} LDAP_BERVAL, *PLDAP_BERVAL, BERVAL, *PBERVAL, BerValue;