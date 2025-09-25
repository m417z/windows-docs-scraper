typedef struct ldapcontrolA {
  PCHAR         ldctl_oid;
  struct berval ldctl_value;
  BOOLEAN       ldctl_iscritical;
} LDAPControlA, *PLDAPControlA;