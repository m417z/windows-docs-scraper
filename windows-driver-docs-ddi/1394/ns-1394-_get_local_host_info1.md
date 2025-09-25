# _GET_LOCAL_HOST_INFO1 structure

## Description

The GET_LOCAL_HOST_INFO1 structure contains the data returned by a [REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request using **u.GetLocalHostInformation.nLevel** GET_HOST_UNIQUE_ID.

## Members

### `UniqueId`

The bus driver fills in this member with the IEEE 1394 globally unique device ID for the host controller.

## See also

[REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)