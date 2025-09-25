typedef enum _AUTHZ_CONTEXT_INFORMATION_CLASS {
  AuthzContextInfoUserSid = 1,
  AuthzContextInfoGroupsSids,
  AuthzContextInfoRestrictedSids,
  AuthzContextInfoPrivileges,
  AuthzContextInfoExpirationTime,
  AuthzContextInfoServerContext,
  AuthzContextInfoIdentifier,
  AuthzContextInfoSource,
  AuthzContextInfoAll,
  AuthzContextInfoAuthenticationId,
  AuthzContextInfoSecurityAttributes,
  AuthzContextInfoDeviceSids,
  AuthzContextInfoUserClaims,
  AuthzContextInfoDeviceClaims,
  AuthzContextInfoAppContainerSid,
  AuthzContextInfoCapabilitySids
} AUTHZ_CONTEXT_INFORMATION_CLASS;