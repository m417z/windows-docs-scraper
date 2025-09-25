# OPM_STANDARD_INFORMATION structure

## Description

Contains the result from an [Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager) (OPM) status request.

## Members

### `rnRandomNumber`

An [OPM_RANDOM_NUMBER](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_random_number) structure. This structure contains the same 128-bit random number that the application sent to the driver in the [OPM_GET_INFO_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_get_info_parameters) or [OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-coppcompatiblegetinformation) structure.

### `ulStatusFlags`

A bitwise **OR** of [OPM Status Flags](https://learn.microsoft.com/windows/desktop/medfound/opm-status-flags).

### `ulInformation`

Response data. The meaning of this value depends on the status request. For more information, see [OPM Status Requests](https://learn.microsoft.com/windows/desktop/medfound/opm-status-requests).

### `ulReserved`

Reserved for future use. Set to zero.

### `ulReserved2`

Reserved for future use. Set to zero.

## Remarks

The layout of this structure is identical to the [DXVA_COPPStatusData](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ns-dxva9typ-dxva_coppstatusdata) structure used in Certified Output Protection Protocol (COPP).

## See also

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)