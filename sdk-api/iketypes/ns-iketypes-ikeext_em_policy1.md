# IKEEXT_EM_POLICY1 structure

## Description

The **IKEEXT_EM_POLICY1** structure is used to store AuthIP's extended mode negotiation policy.
[IKEEXT_EM_POLICY2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_em_policy2) is available. For Windows Vista, [IKEEXT_EM_POLICY0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_em_policy0) is available.

## Members

### `numAuthenticationMethods`

Number of authentication methods in the array.

### `authenticationMethods`

size_is(numAuthenticationMethods)

Array of acceptable authentication methods as specified by [IKEEXT_AUTHENTICATION_METHOD1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_authentication_method1).

### `initiatorImpersonationType`

Type of impersonation.

See [IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_impersonation_type) for more information.

## Remarks

Applies only to AuthIP.

## See also

[IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_impersonation_type)

[IKEEXT_AUTHENTICATION_METHOD1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_authentication_method1)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)