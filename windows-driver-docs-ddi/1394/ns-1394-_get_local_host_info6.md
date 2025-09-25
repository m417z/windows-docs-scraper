# _GET_LOCAL_HOST_INFO6 structure

## Description

The GET_LOCAL_HOST_INFO6 structure contains the data returned by a [REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request using **u.GetLocalHostInformation.nLevel** = GET_HOST_CSR_CONTENTS.

## Members

### `CsrBaseAddress`

Specifies the base address to examine in the CSR. **CsrBaseAddress.Off_High** must be INITIAL_REGISTER_SPACE_HI. The possible values of **CsrBaseAddress.Off_Low** are as follows.

| CsrBaseAddress.Off_Low | Type of Data |
| --- | --- |
| SPEED_MAP_LOCATION | The current speed map. The bus driver converts this from big-endian to machine-native format before it returns the data.<br><br>**Note** The new 1394 bus driver provided with Windows 7 does not support the SPEED_MAP_LOCATION flag in the [REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request. The speed map is obsolete in the IEEE-1394a specification. |
| TOPOLOGY_MAP_LOCATION | The current topology map. The bus driver converts this from big-endian to machine-native format before it returns the data. |

### `CsrDataLength`

Specifies the length in bytes of the buffer that **CsrDataBuffer** points to.

### `CsrDataBuffer`

Pointer to the buffer where the bus driver returns the requested CSR data.

## Remarks

When submitted in a REQUEST_GET_LOCAL_HOST_INFO request, if the **CsrDataLength** is smaller than the size of the requested data, STATUS_INVALID_BUFFER_SIZE is returned. In this case, the correct buffer size is filled in the **CsrDataLength** member.

## See also

[GET_LOCAL_HOST_INFO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_get_local_host_info2)

[REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)