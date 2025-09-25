# MPR_DEVICE_1 structure

## Description

The
**MPR_DEVICE_1** structure stores information about a device used for a link in a multilinked demand dial interface. In addition to the information in
[MPR_DEVICE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_device_0),
**MPR_DEVICE_1** contains phone-number information.

## Members

### `szDeviceType`

Specifies a null-terminated string that indicates the device type referenced by **szDeviceName**. See
[MPR_INTERFACE_2](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_interface_2) for a list of possible device types.

### `szDeviceName`

Specifies a null-terminated string that contains the name of the TAPI device to use with this phone-book entry.

### `szLocalPhoneNumber`

Specifies a null-terminated Unicode string that contains a telephone number. The router uses the **szLocalPhoneNumber** string as the entire phone number.

### `szAlternates`

Pointer to a list of consecutive null-terminated Unicode strings. The last string is terminated by two consecutive null characters. The strings are alternate phone numbers that the router dials in the order listed if the primary number (see **szLocalPhoneNumber**) fails to connect.

## See also

[MPR_DEVICE_0](https://learn.microsoft.com/windows/desktop/api/mprapi/ns-mprapi-mpr_device_0)

[MprAdminInterfaceDeviceGetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacedevicegetinfo)

[MprAdminInterfaceDeviceSetInfo](https://learn.microsoft.com/windows/desktop/api/mprapi/nf-mprapi-mpradmininterfacedevicesetinfo)