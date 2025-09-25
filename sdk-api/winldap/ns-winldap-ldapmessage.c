typedef struct ldapmsg {
  ULONG          lm_msgid;
  ULONG          lm_msgtype;
  PVOID          lm_ber;
  struct ldapmsg *lm_chain;
  struct ldapmsg *lm_next;
  ULONG          lm_time;
  PLDAP          Connection;
  PVOID          Request;
  ULONG          lm_returncode;
  USHORT         lm_referral;
  BOOLEAN        lm_chased;
  BOOLEAN        lm_eom;
  BOOLEAN        ConnectionReferenced;
} LDAPMessage, *PLDAPMessage;