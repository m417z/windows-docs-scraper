WINLDAPAPI INT LDAPAPI ldap_create_vlv_controlA(
  [in]  PLDAP         ExternalHandle,
  [in]  PLDAPVLVInfo  VlvInfo,
  [in]  UCHAR         IsCritical,
  [out] PLDAPControlA *Control
);