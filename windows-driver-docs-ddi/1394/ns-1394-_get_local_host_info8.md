# _GET_LOCAL_HOST_INFO8 structure

## Description

The **GET_LOCAL_HOST_INFO8** structure contains the data returned by a [REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request with **u.GetLocalHostInformation.nLevel** set to GET_HOST_DDI_VERSION.

## Members

### `MajorVersion`

The major version of the 1394 bus driver interface.

### `MinorVersion`

The minor version of the 1394 bus driver interface.

## Remarks

A client driver can determine whether the 1394 bus driver
loaded in the IEEE 1394 driver stack is the new 1394 bus driver or the legacy
1394 bus driver. A new **nLevel** value has been added
to the [REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) I/O
request to return the version of the DDIs that the 1394 bus driver supports.

To determine whether the 1394 bus driver is the new 1394 bus
driver or the legacy 1394 bus driver,

1. The client driver must send
   the [REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request with **nLevel**
   set to GET_HOST_DDI_VERSION. If the driver stack contains the new 1394 bus
   driver, the request returns a status value of STATUS_SUCCESS. Otherwise, the
   legacy 1394 bus driver returns a status value of
   STATUS_INVALID_PARAMETER.
2. The client driver must also provide a
   pointer to a caller-allocated **GET_LOCAL_HOST_INFO8** structure in
   **u.GetLocalHostInformation.Information**. Upon
   successful completion, the new 1394 bus driver (1394ohci.sys bus driver)sets the **MajorVersion** and **MinorVersion** members as follows.
   * BUS1394_DDI_MAJOR_VERSION: The major version of the 1394 bus driver interface.
   * BUS1394_DDI_MINOR_VERSION: The minor version of the 1394 bus driver interface.