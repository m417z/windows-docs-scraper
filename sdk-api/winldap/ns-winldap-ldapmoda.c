typedef struct ldapmodA {
  ULONG mod_op;
  PCHAR mod_type;
  union {
    PCHAR  *modv_strvals;
    berval **modv_bvals;
  } mod_vals;
} LDAPModA, *PLDAPModA;