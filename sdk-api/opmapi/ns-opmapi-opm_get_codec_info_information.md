# OPM_GET_CODEC_INFO_INFORMATION structure

## Description

Contains the result from an [OPM_GET_CODEC_INFO](https://learn.microsoft.com/windows/desktop/medfound/opm-get-codec-info) query.

## Members

### `rnRandomNumber`

An [OPM_RANDOM_NUMBER](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_random_number) structure. This structure contains the same 128-bit random number that the application sent to the driver in the [OPM_GET_INFO_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_get_info_parameters) structure.

### `Merit`

The merit value of the codec.

## See also

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)