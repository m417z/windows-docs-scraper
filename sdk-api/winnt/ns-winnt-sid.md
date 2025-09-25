# SID structure

## Description

The security identifier (SID) structure is a variable-length structure used to uniquely identify users or groups.

Applications should not modify a SID directly. To create and manipulate a security identifier, use the functions listed in the See Also section.

## Members

## See also

[AllocateAndInitializeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-allocateandinitializesid)

[ConvertSidToStringSid](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertsidtostringsida)

[ConvertStringSidToSid](https://learn.microsoft.com/windows/desktop/api/sddl/nf-sddl-convertstringsidtosida)

[CopySid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-copysid)

[EqualSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-equalsid)

[FreeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-freesid)

[GetLengthSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getlengthsid)

[GetSidIdentifierAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsididentifierauthority)

[GetSidLengthRequired](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidlengthrequired)

[GetSidSubAuthority](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthority)

[GetSidSubAuthorityCount](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-getsidsubauthoritycount)

[InitializeSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-initializesid)

[IsValidSid](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsid)

[LookupAccountName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountnamea)

[LookupAccountSid](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountsida)

[SID Components](https://learn.microsoft.com/windows/desktop/SecAuthZ/sid-components)