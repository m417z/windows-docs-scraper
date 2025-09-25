# IKEEXT_KERBEROS_AUTHENTICATION0 structure

## Description

The **IKEEXT_KERBEROS_AUTHENTICATION0** structure contains information needed for preshared key authentication.
[IKEEXT_KERBEROS_AUTHENTICATION1](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_certificate_authentication1) is available.

## Members

### `flags`

A combination of the following values.

| Kerberos authentication flag | Meaning |
| --- | --- |
| **IKEEXT_KERB_AUTH_DISABLE_INITIATOR_TOKEN_GENERATION** | Disable initiator generation of peer token from the peer's name string. |
| **IKEEXT_KERB_AUTH_DONT_ACCEPT_EXPLICIT_CREDENTIALS** | Refuse connections if the peer is using explicit credentials.<br><br>Applicable only to AuthIP. |

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)