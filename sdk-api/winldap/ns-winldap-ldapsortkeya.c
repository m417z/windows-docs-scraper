typedef struct ldapsortkeyA {
  PCHAR   sk_attrtype;
  PCHAR   sk_matchruleoid;
  BOOLEAN sk_reverseorder;
} LDAPSortKeyA, *PLDAPSortKeyA;