# _PMI_MEASUREMENT_DATA structure

## Description

The PMI_MEASUREMENT_DATA structure contains the current power measurement that is collected by a power meter.

## Members

### `Version`

A value that specifies the version of this structure. For Windows 7, Windows Server 2008 R2, and later versions of Windows, this value must be 1.

### `CurrentPower`

A value, in units of milliwatts (mW), that specifies the current power meter measurement.

## Remarks

The PMI_MEASUREMENT_DATA structure is returned through an [IOCTL_PMI_GET_MEASUREMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_measurement) I/O control (IOCTL) query request. If the query request completes successfully, the request returns a PMI_MEASUREMENT_DATA structure.

## See also

[IOCTL_PMI_GET_MEASUREMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pmi/ni-pmi-ioctl_pmi_get_measurement)