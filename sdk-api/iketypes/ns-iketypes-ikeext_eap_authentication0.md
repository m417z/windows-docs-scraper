# IKEEXT_EAP_AUTHENTICATION0 structure

## Description

The **IKEEXT_EAP_AUTHENTICATION0** structure stores information needed for Extensible Authentication Protocol (EAP) authentication.
This structure is only applicable to IKEv2.

## Members

### `flags`

A combination of the following values.

| Pre-shared key authentication flag. | Meaning |
| --- | --- |
| **IKEEXT_EAP_FLAG_LOCAL_AUTH_ONLY** | Specifies that EAP authentication will be used only to authenticate a local computer to a remote computer. |
| **IKEEXT_EAP_FLAG_REMOTE_AUTH_ONLY** | Specifies that EAP authentication will be used only to authenticate a remote computer to a local computer. |

## Remarks

**IKEEXT_EAP_AUTHENTICATION0** is a specific implementation of IKEEXT_EAP_AUTHENTICATION. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)