typedef struct ldapmodW {
  ULONG  mod_op;
  PWCHAR mod_type;
  union {
    PWCHAR *modv_strvals;
    berval **modv_bvals;
  } mod_vals;
} LDAPModW, *PLDAPModW;