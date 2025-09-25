# IKEEXT_EM_POLICY2 structure

## Description

The **IKEEXT_EM_POLICY2** structure is used to store AuthIP's extended mode negotiation policy.
[IKEEXT_EM_POLICY0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_em_policy0) is available.

## Members

### `numAuthenticationMethods`

Type: **UINT32**

 Number of authentication methods in the array.

### `authenticationMethods`

Type: [IKEEXT_AUTHENTICATION_METHOD2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_authentication_method2)*

size_is(numAuthenticationMethods)

Array of acceptable authentication methods.

### `initiatorImpersonationType`

Type: **[IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_impersonation_type)**

Type of impersonation.

## See also

[IKEEXT_AUTHENTICATION_IMPERSONATION_TYPE](https://learn.microsoft.com/windows/win32/api/iketypes/ne-iketypes-ikeext_authentication_impersonation_type)

[IKEEXT_AUTHENTICATION_METHOD2](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_authentication_method2)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)