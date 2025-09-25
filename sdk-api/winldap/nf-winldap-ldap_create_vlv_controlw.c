WINLDAPAPI INT LDAPAPI ldap_create_vlv_controlW(
  [in]  PLDAP         ExternalHandle,
  [in]  PLDAPVLVInfo  VlvInfo,
  [in]  UCHAR         IsCritical,
  [out] PLDAPControlW *Control
);