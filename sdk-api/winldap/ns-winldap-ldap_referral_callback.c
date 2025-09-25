typedef struct LdapReferralCallback {
  ULONG                 SizeOfCallbacks;
  QUERYFORCONNECTION    *QueryForConnection;
  NOTIFYOFNEWCONNECTION *NotifyRoutine;
  DEREFERENCECONNECTION *DereferenceRoutine;
} LDAP_REFERRAL_CALLBACK, *PLDAP_REFERRAL_CALLBACK;