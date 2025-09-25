# OPM_SET_PROTECTION_LEVEL_PARAMETERS structure

## Description

Contains data for the [OPM_SET_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/medfound/opm-set-protection-level) command in [Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager) (OPM).

## Members

### `ulProtectionType`

Identifies the protection mechanism. For a list of possible values, see [OPM Protection Type Flags](https://learn.microsoft.com/windows/desktop/medfound/opm-protection-type-flags).

### `ulProtectionLevel`

Specifies the protection level. The meaning of this value depends on the protection mechanism that is queried. For each protection mechanism, the value is a flag from a different enumeration, as shown in the following table.

| Protection mechanism | Enumeration |
| --- | --- |
| ACP | [OPM_ACP_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/api/opmapi/ne-opmapi-opm_acp_protection_level) |
| CGMS-A | [CGMS-A Protection Flags](https://learn.microsoft.com/windows/desktop/medfound/cgms-a-protection-flags) |
| DPCP | [OPM_DPCP_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/api/opmapi/ne-opmapi-opm_dpcp_protection_level) |
| HDCP | [OPM_HDCP_PROTECTION_LEVEL](https://learn.microsoft.com/windows/desktop/api/opmapi/ne-opmapi-opm_hdcp_protection_level) |

### `Reserved`

Reserved for future use. Set to zero.

### `Reserved2`

Reserved for future use. Set to zero.

## Remarks

The layout of this structure is identical to the [DXVA_COPPSetProtectionLevelCmdData](https://learn.microsoft.com/windows/win32/api/dxva9typ/ns-dxva9typ-dxva_coppsetprotectionlevelcmddata) structure used in Certified Output Protection Protocol (COPP).

## See also

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)