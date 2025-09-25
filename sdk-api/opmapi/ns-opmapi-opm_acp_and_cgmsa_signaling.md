# OPM_ACP_AND_CGMSA_SIGNALING structure

## Description

Contains the result from an [OPM_GET_ACP_AND_CGMSA_SIGNALING](https://learn.microsoft.com/windows/desktop/medfound/opm-get-acp-and-cgmsa-signaling) query.

## Members

### `rnRandomNumber`

An [OPM_RANDOM_NUMBER](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_random_number) structure. This structure contains the same 128-bit random number that the application sent to the driver in the [OPM_GET_INFO_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_get_info_parameters) or [OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-coppcompatiblegetinformation) structure.

### `ulStatusFlags`

A bitwise **OR** of [OPM Status Flags](https://learn.microsoft.com/windows/desktop/medfound/opm-status-flags).

### `ulAvailableTVProtectionStandards`

A bitwise **OR** of zero or more [TV Protection Standard Flags](https://learn.microsoft.com/windows/desktop/medfound/tv-protection-standard-flags). The driver will return flags for all of the protection standards and resolutions that it supports, regardless of which are now active.

### `ulActiveTVProtectionStandard`

One value from the [TV Protection Standard Flags](https://learn.microsoft.com/windows/desktop/medfound/tv-protection-standard-flags), indicating the protection standard that is currently active.

### `ulReserved`

Reserved for future use. Set to zero.

### `ulAspectRatioValidMask1`

A bitmask indicating which bits of **ulAspectRatioData1** are valid.

### `ulAspectRatioData1`

The current aspect ratio. For EN 300 294, the value is a member of the [OPM_IMAGE_ASPECT_RATIO_EN300294](https://learn.microsoft.com/windows/desktop/api/opmapi/ne-opmapi-opm_image_aspect_ratio_en300294) enumeration.

### `ulAspectRatioValidMask2`

A bitmask indicating which bits of **ulAspectRatioData2** are valid.

### `ulAspectRatioData2`

An additional data element related to aspect ratio for the current protection standard. The presence and meaning of this data depends on the protection standard. This field can be used to convey End and Q0 bits for EIA-608-B, or the active format description for CEA-805-A.

### `ulAspectRatioValidMask3`

A bitmask indicating which bits of **ulAspectRatioData3** are valid.

### `ulAspectRatioData3`

An additional data element related to aspect ratio for the current protection standard. The presence and meaning of this data depends on the protection standard.

### `ulReserved2`

Reserved for future use. Fill this array with zeros.

### `ulReserved3`

Reserved for future use.Fill this array with zeros.

## Remarks

The layout of this structure is identical to the [DXVA_COPPStatusSignalingCmdData](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ns-dxva9typ-dxva_coppstatussignalingcmddata) structure used in Certified Output Protection Protocol (COPP).

## See also

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)