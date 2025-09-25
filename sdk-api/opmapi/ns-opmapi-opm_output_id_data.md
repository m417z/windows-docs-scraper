# OPM_OUTPUT_ID_DATA structure

## Description

Contains the result from an [OPM_GET_OUTPUT_ID](https://learn.microsoft.com/windows/desktop/medfound/opm-get-output-id) status request.

## Members

### `rnRandomNumber`

An [OPM_RANDOM_NUMBER](https://learn.microsoft.com/windows/win32/api/opmapi/ns-opmapi-opm_copp_compatible_get_info_parameters) structure. This structure contains the same 128-bit random number that the application sent to the driver in the [OPM_GET_INFO_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_get_info_parameters) or [OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/opmapi/ns-opmapi-opm_copp_compatible_get_info_parameters) structure.

### `ulStatusFlags`

A bitwise **OR** of [OPM Status Flags](https://learn.microsoft.com/windows/desktop/medfound/opm-status-flags).

### `OutputId`

The unique identifier of the monitor associated with this video output.

## See also

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)