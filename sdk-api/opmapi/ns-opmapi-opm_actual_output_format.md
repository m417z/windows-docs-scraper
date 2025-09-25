# OPM_ACTUAL_OUTPUT_FORMAT structure

## Description

Contains the result of an [OPM_GET_ACTUAL_OUTPUT_FORMAT](https://learn.microsoft.com/windows/desktop/medfound/opm-get-actual-output-format) query in [Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager) (OPM).

## Members

### `rnRandomNumber`

An [OPM_RANDOM_NUMBER](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_random_number) structure. This structure contains the same 128-bit random number that the application sent to the driver in the [OPM_GET_INFO_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/ksopmapi/ns-ksopmapi-opm_get_info_parameters) or [OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS](https://learn.microsoft.com/windows/desktop/api/opmapi/nf-opmapi-iopmvideooutput-coppcompatiblegetinformation) structure.

### `ulStatusFlags`

A bitwise **OR** of [OPM Status Flags](https://learn.microsoft.com/windows/desktop/medfound/opm-status-flags).

### `ulDisplayWidth`

The width of the display mode, in pixels.

### `ulDisplayHeight`

The height of the display mode, in pixels.

### `dsfSampleInterleaveFormat`

A [DXVA2_SampleFormat](https://learn.microsoft.com/windows/desktop/api/dxva2api/ne-dxva2api-dxva2_sampleformat) value that describes the interlace mode.

### `d3dFormat`

A **D3DFORMAT** value that describes the video format.

### `ulFrequencyNumerator`

The numerator of the refresh rate of the current display mode.

### `ulFrequencyDenominator`

The denominator of the refresh rate of the current display mode.

## Remarks

The refresh rate is expressed as a fraction. For example, if the refresh rate is 72 Hz, **FreqNumerator** = 72 and **FreqDenominator** = 1. For NTSC television, the values are **FreqNumerator** = 60000 and **FreqDenominator** = 1001 (59.94 fields per second).

The layout of this structure is identical to the [DXVA_COPPStatusDisplayData](https://learn.microsoft.com/windows/desktop/api/dxva9typ/ns-dxva9typ-dxva_coppstatusdisplaydata) structure used in Certified Output Protection Protocol (COPP).

## See also

[OPM Structures](https://learn.microsoft.com/windows/desktop/medfound/opm-structures)

[Output Protection Manager](https://learn.microsoft.com/windows/desktop/medfound/output-protection-manager)