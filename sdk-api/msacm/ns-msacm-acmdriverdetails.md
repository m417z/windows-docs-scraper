# ACMDRIVERDETAILS structure

## Description

The **ACMDRIVERDETAILS** structure describes the features of an ACM driver.

## Members

### `cbStruct`

Size, in bytes, of the valid information contained in the **ACMDRIVERDETAILS** structure. An application should initialize this member to the size, in bytes, of the desired information. The size specified in this member must be large enough to contain the **cbStruct** member of the **ACMDRIVERDETAILS** structure. When the [acmDriverDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriverdetails) function returns, this member contains the actual size of the information returned. The returned information will never exceed the requested size.

### `fccType`

Type of the driver. For ACM drivers, set this member to ACMDRIVERDETAILS_FCCTYPE_AUDIOCODEC.

### `fccComp`

Subtype of the driver. This member is currently set to ACMDRIVERDETAILS_FCCCOMP_UNDEFINED (zero).

### `wMid`

Manufacturer identifier. Manufacturer identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `wPid`

Product identifier. Product identifiers are defined in [Manufacturer and Product Identifiers](https://learn.microsoft.com/windows/desktop/Multimedia/manufacturer-and-product-identifiers).

### `vdwACM`

Version of the ACM for which this driver was compiled. The version number is a hexadecimal number in the format 0xAABBCCCC, where AA is the major version number, BB is the minor version number, and CCCC is the build number. The version parts (major, minor, and build) should be displayed as decimal numbers.

### `vdwDriver`

Version of the driver. The version number is a hexadecimal number in the format 0xAABBCCCC, where AA is the major version number, BB is the minor version number, and CCCC is the build number. The version parts (major, minor, and build) should be displayed as decimal numbers.

### `fdwSupport`

Support flags for the driver. The following values are defined:

| Name | Description |
| --- | --- |
| **ACMDRIVERDETAILS_SUPPORTF_ASYNC** | Driver supports asynchronous conversions. |
| **ACMDRIVERDETAILS_SUPPORTF_CODEC** | Driver supports conversion between two different format tags. For example, if a driver supports compression from WAVE_FORMAT_PCM to WAVE_FORMAT_ADPCM, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_CONVERTER** | Driver supports conversion between two different formats of the same format tag. For example, if a driver supports resampling of WAVE_FORMAT_PCM, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_DISABLED** | Driver has been disabled. This flag is set by the ACM for a driver when it has been disabled for any of a number of reasons. Disabled drivers cannot be opened and can be used only under very limited circumstances. |
| **ACMDRIVERDETAILS_SUPPORTF_FILTER** | Driver supports a filter (modification of the data without changing any of the format attributes). For example, if a driver supports volume or echo operations on WAVE_FORMAT_PCM, this flag is set. |
| **ACMDRIVERDETAILS_SUPPORTF_HARDWARE** | Driver supports hardware input, output, or both through a waveform-audio device. An application should use the [acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics) function with the ACM_METRIC_HARDWARE_WAVE_INPUT and ACM_METRIC_HARDWARE_WAVE_OUTPUT metric indexes to get the waveform-audio device identifiers associated with the supporting ACM driver. |
| **ACMDRIVERDETAILS_SUPPORTF_LOCAL** | The driver has been installed locally with respect to the current task. |

### `cFormatTags`

Number of unique format tags supported by this driver.

### `cFilterTags`

Number of unique filter tags supported by this driver.

### `hicon`

Handle to a custom icon for this driver. An application can use this icon for referencing the driver visually. This member can be **NULL**.

### `szShortName`

Null-terminated string that describes the name of the driver. This string is intended to be displayed in small spaces.

### `szLongName`

Null-terminated string that describes the full name of the driver. This string is intended to be displayed in large (descriptive) spaces.

### `szCopyright`

Null-terminated string that provides copyright information for the driver.

### `szLicensing`

Null-terminated string that provides special licensing information for the driver.

### `szFeatures`

Null-terminated string that provides special feature information for the driver.

## See also

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)

[Audio Compression Structures](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-structures)

[acmDriverDetails](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriverdetails)

[acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics)