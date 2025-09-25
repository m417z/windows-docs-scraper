# IMAPI_MODE_PAGE_TYPE enumeration

## Description

Defines values for the mode pages that are supported by CD and DVD devices.

## Constants

### `IMAPI_MODE_PAGE_TYPE_READ_WRITE_ERROR_RECOVERY:0x1`

The mode page specifies the error recovery parameters the
drive uses during any command that performs a data read or write operation from the media.

### `IMAPI_MODE_PAGE_TYPE_MRW:0x3`

The mode page provides a method by which the host may control the special features of a
MRW CD-RW Drive.

### `IMAPI_MODE_PAGE_TYPE_WRITE_PARAMETERS:0x5`

The mode page provides parameters that are often needed in the execution of
commands that write to the media.

### `IMAPI_MODE_PAGE_TYPE_CACHING:0x8`

The mode page contains parameters to enable or disable caching during read or write operations.

### `IMAPI_MODE_PAGE_TYPE_INFORMATIONAL_EXCEPTIONS:0x1c`

The mode page contains parameters for exception reporting mechanisms that result in specific sense code errors when failures are predicted. This mode page is related to the [S.M.A.R.T.](https://learn.microsoft.com/windows/desktop/api/imapi2/ne-imapi2-imapi_feature_page_type) feature.

### `IMAPI_MODE_PAGE_TYPE_TIMEOUT_AND_PROTECT:0x1d`

The mode page contains command time-out values that are suggested by the device.

### `IMAPI_MODE_PAGE_TYPE_POWER_CONDITION:0x1a`

The mode page contains power management settings for the drive. The parameters define how long the logical unit delays before changing its internal power state.

### `IMAPI_MODE_PAGE_TYPE_LEGACY_CAPABILITIES:0x2a`

The mode page contains legacy device capabilities. These are superseded by the feature pages returned through the GetConfiguration command.

## Remarks

Note that the range of mode page type values is 0x0000 to 0xFFFF. This enumeration contains those features defined in the Multimedia Commands - 5 (MMC) specification. For a complete definition of each feature, see Mode Parameters for Multi-Media Devices in the latest release of the MMC specification at ftp://ftp.t10.org/t10/drafts/mmc5.

## See also

[IDiscRecorder2::get_SupportedModePages](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-get_supportedmodepages)

[IDiscRecorder2Ex::GetModePage](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-getmodepage)

[IDiscRecorder2Ex::GetSupportedModePages](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-getsupportedmodepages)