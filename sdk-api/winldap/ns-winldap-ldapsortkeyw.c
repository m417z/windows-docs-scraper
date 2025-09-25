typedef struct ldapsortkeyW {
  PWCHAR  sk_attrtype;
  PWCHAR  sk_matchruleoid;
  BOOLEAN sk_reverseorder;
} LDAPSortKeyW, *PLDAPSortKeyW;