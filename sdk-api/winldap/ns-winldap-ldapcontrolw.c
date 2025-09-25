typedef struct ldapcontrolW {
  PWCHAR        ldctl_oid;
  struct berval ldctl_value;
  BOOLEAN       ldctl_iscritical;
} LDAPControlW, *PLDAPControlW;