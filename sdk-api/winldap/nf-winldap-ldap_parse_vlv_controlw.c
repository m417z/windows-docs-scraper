WINLDAPAPI INT LDAPAPI ldap_parse_vlv_controlW(
  [in]  PLDAP         ExternalHandle,
  [in]  PLDAPControlW *Control,
  [out] PULONG        TargetPos,
  [out] PULONG        ListCount,
  [out] PBERVAL       *Context,
  [out] PINT          ErrCode
);