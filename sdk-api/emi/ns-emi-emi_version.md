# EMI_VERSION structure

## Description

The **EMI_VERSION** structure describes the version of the Energy Metering Interface (EMI) that is supported by a device.

## Members

### `EmiVersion`

The version of the Energy Metering Interface (EMI) that is supported by a device. Currently, the only supported version is **EMI_VERSION_V1** (as defined in emi.h).

## Remarks

This structure is returned through a successful completion of an [IOCTL_EMI_GET_VERSION](https://learn.microsoft.com/windows/desktop/api/emi/ni-emi-ioctl_emi_get_version) IOCTL request.

## See also

[Energy Metering Interface](https://learn.microsoft.com/windows-hardware/drivers/powermeter/energy-meter-interface)

[IOCTL_EMI_GET_VERSION](https://learn.microsoft.com/windows/desktop/api/emi/ni-emi-ioctl_emi_get_version)