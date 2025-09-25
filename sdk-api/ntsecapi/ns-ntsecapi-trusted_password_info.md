# TRUSTED_PASSWORD_INFO structure

## Description

The **TRUSTED_PASSWORD_INFO** structure is used to query or set the password for a trusted domain. The
[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo) and
[LsaSetTrustedDomainInformation](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasettrusteddomaininformation) functions use this structure when their *InformationClass* parameters are set to TrustedPasswordInformation.

## Members

### `Password`

An
[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the password to use when creating an authenticated connection to the domain.

### `OldPassword`

An [LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string) structure that contains the old password. On set operations, if the **Buffer** member of this structure is **NULL**, the old password is set to the current password.

## Remarks

When you have finished using the **TRUSTED_PASSWORD_INFO** structure, clear the sensitive information from memory by calling the [SecureZeroMemory](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa366877(v=vs.85)) function. For more information about protecting passwords, see [Handling Passwords](https://learn.microsoft.com/windows/desktop/SecBP/handling-passwords).

## See also

[LSA_UNICODE_STRING](https://learn.microsoft.com/windows/desktop/api/lsalookup/ns-lsalookup-lsa_unicode_string)

[LsaQueryTrustedDomainInfo](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaquerytrusteddomaininfo)

[LsaSetTrustedDomainInformation](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasettrusteddomaininformation)

[TRUSTED_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-trusted_information_class)