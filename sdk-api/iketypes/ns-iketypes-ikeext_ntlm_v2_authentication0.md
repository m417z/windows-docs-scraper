# IKEEXT_NTLM_V2_AUTHENTICATION0 structure

## Description

The **IKEEXT_NTLM_V2_AUTHENTICATION0** structure contains information needed for Microsoft Windows NT LAN Manager (NTLM) V2 authentication.

## Members

### `flags`

Possible value:

| NTLM authentication flag | Meaning |
| --- | --- |
| **IKEEXT_NTLM_V2_AUTH_DONT_ACCEPT_EXPLICIT_CREDENTIALS** | Refuse connections if the peer is using explicit credentials. |

## Remarks

**IKEEXT_NTLM_V2_AUTHENTICATION0** is a specific implementation of IKEEXT_NTLM_V2_AUTHENTICATION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)