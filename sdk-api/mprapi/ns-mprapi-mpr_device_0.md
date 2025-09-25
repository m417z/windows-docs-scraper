# MPR_DEVICE_0 structure

## Description

The
**MPR_DEVICE_0** structure stores information about a device used for a link in a multilinked demand dial interface.

## Members

### `szDeviceType`

Specifies a null-terminated string that indicates the RAS device type referenced by **szDeviceName**. See
[MPR_INTERFACE_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_2) for a list of possible device types.

### `szDeviceName`

Specifies a null-terminated string that contains the name of the TAPI device to use with this phone-book entry.

## See also

[MPR_DEVICE_1](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_device_1)

[MprAdminInterfaceDeviceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacedevicegetinfo)

[MprAdminInterfaceDeviceSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacedevicesetinfo)