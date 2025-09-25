## Description

The **GNSS_BREADCRUMBING_PARAM** structure contains the configuration passed into the start of breadcrumbing via [IOCTL_GNSS_START_BREADCRUMBING](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ni-gnssdriver-ioctl_gnss_start_breadcrumbing).

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `MaximumHorizontalUncertainty`

Contains the maximum horizontal uncertainty value. Any fix with an error radius larger than this value shall not be recorded.

### `MinDistanceBetweenFixes`

Contains the minimum distance between fixes. Only record a fix if the center of it is at least as far apart as this value from center of the last fix, using a Haversine distance calculation.

### `MaximumErrorTimeoutMs`

Contains the maximum error timeout in milliseconds. If the location of the device is unknown for this duration, an error must be recorded in the breadcrumb data. Errors can be recorded earlier if they were already known.

### `Unused`

Padding buffer reserved for future use.