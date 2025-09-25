# OPM_SET_ACP_AND_CGMSA_SIGNALING_PARAMETERS structure

## Description

Contains information for the [OPM_SET_ACP_AND_CGMSA_SIGNALING](https://learn.microsoft.com/windows/desktop/medfound/opm-set-acp-and-cgmsa-signaling) command in [Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager) (OPM).

This command causes the driver to insert Wide Screen Signaling (WSS) codes or other data packets in the television signal, as required by some Analog Copy Protection (ACP) and Copy Generation Management System — Analog (CGMS-A) specifications. For example:

* ETSI EN 300 294 (625i PAL): Data packets are inserted into line 23 of the signal.
* CEA-608-B (NTSC): Data packets are inserted into line 21 of the vertical blanking interval (VBI).

## Members

### `ulNewTVProtectionStandard`

Specifies the protection standard and format that is currently active. The value is a bitwise **OR** of [TV Protection Standard Flags](https://learn.microsoft.com/windows/desktop/medfound/tv-protection-standard-flags).

### `ulAspectRatioChangeMask1`

A bitmask indicating which bits from **ulAspectRatioData1** to set in the signal.

### `ulAspectRatioData1`

Specifies the aspect ratio value to be set for the current protection standard. For EN 300 294, use the [OPM_IMAGE_ASPECT_RATIO_EN300294](https://learn.microsoft.com/windows/desktop/api/opmapi/ne-opmapi-opm_image_aspect_ratio_en300294) enumeration.

### `ulAspectRatioChangeMask2`

A bitmask indicating which bits from **ulAspectRatioData2** to set in the signal.

### `ulAspectRatioData2`

An additional data element related to aspect ratio. The presence and meaning of this data depends on the protection standard. This field can be used to convey End and Q0 bits for EIA-608-B, or the active format description for CEA-805-A.

### `ulAspectRatioChangeMask3`

A bitmask indicating which bits from **ulAspectRatioData3** to set in the signal.

### `ulAspectRatioData3`

An additional data element related to aspect ratio for the current protection standard. The presence and meaning of this data depends on the protection standard.

### `ulReserved`

Reserved for future use. Set the entire array to zero.

### `ulReserved2`

Reserved for future use. Set the entire array to zero.

### `ulReserved3`

Reserved for future use. Set to zero.

## Remarks

The layout of this structure is identical to the [DXVA_COPPSetSignalingCmdData](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ns-dxva9typ-dxva_coppsetsignalingcmddata) structure used in Certified Output Protection Manager (COPP).

## See also

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)