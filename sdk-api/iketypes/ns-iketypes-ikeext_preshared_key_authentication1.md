# IKEEXT_PRESHARED_KEY_AUTHENTICATION1 structure

## Description

The **IKEEXT_PRESHARED_KEY_AUTHENTICATION1** structure stores information needed for pre-shared key authentication.
[IKEEXT_PRESHARED_KEY_AUTHENTICATION0](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_eap_authentication0) is available.

## Members

### `presharedKey`

The pre-shared key specified by [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob).

### `flags`

A combination of the following values.

| Pre-shared key authentication flag | Meaning |
| --- | --- |
| **IKEEXT_PSK_FLAG_LOCAL_AUTH_ONLY** | Specifies that the pre-shared key authentication will be used only to authenticate a local computer to a remote computer.<br><br>Applicable only to IKEv2. |
| **IKEEXT_PSK_FLAG_REMOTE_AUTH_ONLY** | Specifies that the pre-shared key authentication will be used only to authenticate a remote computer to a local computer.<br><br>Applicable only to IKEv2. |

## See also

[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_byte_blob)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)