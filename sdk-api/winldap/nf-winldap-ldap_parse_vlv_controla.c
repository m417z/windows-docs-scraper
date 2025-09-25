WINLDAPAPI INT LDAPAPI ldap_parse_vlv_controlA(
  [in]  PLDAP         ExternalHandle,
  [in]  PLDAPControlA *Control,
  [out] PULONG        TargetPos,
  [out] PULONG        ListCount,
  [out] PBERVAL       *Context,
  [out] PINT          ErrCode
);