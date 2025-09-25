# _GET_LOCAL_HOST_INFO3 structure

## Description

The GET_LOCAL_HOST_INFO3 structure contains the data returned by a [REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request using **u.GetLocalHostInformation.nLevel** = GET_POWER_SUPPLIED.

## Members

### `deciWattsSupplied`

Specifies the wattage supplied, in tenths of a watt.

### `Voltage`

Specifies the voltage, in tenths of a volt.

## See also

[REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)