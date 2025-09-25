# IKEEXT_KERBEROS_AUTHENTICATION1 structure

## Description

The **IKEEXT_KERBEROS_AUTHENTICATION1** structure contains information needed for preshared key authentication.
[IKEEXT_KERBEROS_AUTHENTICATION0](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_eap_authentication0) is available.

## Members

### `flags`

Type: **UINT32**

A combination of the following values.

| Kerberos authentication flag | Meaning |
| --- | --- |
| **IKEEXT_KERB_AUTH_DISABLE_INITIATOR_TOKEN_GENERATION** | Disable initiator generation of peer token from the peer's name string. |
| **IKEEXT_KERB_AUTH_DONT_ACCEPT_EXPLICIT_CREDENTIALS** | Refuse connections if the peer is using explicit credentials.<br><br>Applicable only to AuthIP. |
| **IKEEXT_KERB_AUTH_FORCE_PROXY_ON_INITIATOR** | Force the use of a Kerberos proxy server when acting as initiator. |

### `proxyServer`

Type: **wchar_t***

The Kerberos proxy server.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)