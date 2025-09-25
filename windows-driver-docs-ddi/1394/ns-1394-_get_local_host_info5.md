# _GET_LOCAL_HOST_INFO5 structure

## Description

The GET_LOCAL_HOST_INFO5 structure contains the data returned by a [REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request using **u.GetLocalHostInformation.nLevel** = GET_HOST_CONFIG_ROM.

## Members

### `ConfigRom`

Pointer to the beginning of the buffer to be filled with the local host's configuration ROM.

### `ConfigRomLength`

Specifies the length of the buffer pointed to by **ConfigRom**.

## Remarks

When submitted in a REQUEST_GET_LOCAL_HOST_INFO request, if the **ConfigRomLength** is smaller than the size of the Configuration ROM, a status code of STATUS_INVALID_BUFFER_SIZE is returned. In this case, the correct buffer size is filled in the **ConfigRomLength** member.

## See also

[REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)