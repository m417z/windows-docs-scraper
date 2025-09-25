## Description

The GNSS_BREADCRUMB_LIST structure contains an [IOCTL_GNSS_POP_BREADCRUMBS](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ni-gnssdriver-ioctl_gnss_pop_breadcrumbs) response.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `NumCrumbs`

The number of breadcrumbs in the **IOCTL_GNSS_POP_BREADCRUMBS** response.

### `v1`

An array of individual breadcrumbs returned in the in the **IOCTL_GNSS_POP_BREADCRUMBS** response.