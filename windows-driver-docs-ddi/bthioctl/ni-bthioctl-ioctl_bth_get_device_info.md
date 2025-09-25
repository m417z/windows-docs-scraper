# IOCTL_BTH_GET_DEVICE_INFO IOCTL

## Description

The IOCTL_BTH_GET_DEVICE_INFO request returns information about all cached, previously discovered
remote radios that are Bluetooth-enabled.

## Parameters

### Major code

### Input buffer

The
**AssociatedIrp.SystemBuffer** member points to a buffer for a
[BTH_DEVICE_INFO_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_device_info_list) structure.

### Input buffer length

The length of a
[BTH_DEVICE_INFO_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_device_info_list) structure

### Output buffer

The
**AssociatedIrp.SystemBuffer** member points to a buffer that holds a
[BTH_DEVICE_INFO_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_device_info_list) structure. The
**numOfDevices** member of the BTH_DEVICE_INFO_LIST structure contains the number of devices for
which there is information and an array of
[BTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bthdef/ns-bthdef-bth_device_info) structures; one array
entry for each device.

### Output buffer length

If the size of the passed output buffer is not exactly `sizeof(BTH_DEVICE_INFO_LIST)` plus the correct multiple of `sizeof(BTH_DEVICE_INFO)`, the request will fail with STATUS_INVALID_BUFFER_SIZE.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the
**Information** member of the STATUS_BLOCK structure is set to the size, in bytes, of the buffer that
holds information about the array of devices. The BTH_DEVICE_INFO_LIST structure contains storage for
the first BTH_DEVICE_INFO structure, so if no devices are returned, the
**Information** member is set to the size of the first structure.

The
**Status** member is set to one of the values in the following table.

| Status value | Description |
| --- | --- |
| STATUS_SUCCESS | The IOCTL completed successfully. |
| STATUS_INVALID_PARAMETER | The input buffer passed in was **NULL**. |
| STATUS_INVALID_BUFFER_SIZE | The output buffer was not sized correctly. |

## Remarks

The IOCTL_BTH_GET_DEVICE_INFO IOCTL provides information about all previously discovered remote
radios.

The
**numOfDevices** member of the BTH_DEVICE_INFO_LIST structure returns the total number of
BTH_DEVICE_INFO structures that are returned by the IOCTL. If the calling driver passes in a buffer that
is smaller than the value of the
**numOfDevices** member, only a portion of the available structures will be returned. Bluetooth driver
developers should call IOCTL_BTH_GET_DEVICE_INFO with a small buffer first, for example
`sizeof(BTH_DEVICE_INFO_LIST)`, and then use the returned
**numOfDevices** member to correctly size the buffer for a subsequent call.

The BTH_DEVICE_INFO_LIST structure includes storage for the first BTH_DEVICE_INFO structure. Use the
following formula to calculate the correct buffer size for a call to IOCTL_BTH_GET_DEVICE_INFO:
`Buffer=sizeof(BTH_DEVICE_INFO_LIST)+(NumOfDevices-1)*sizeof(BTH_DEVICE_INFO)`.

## See also

[BTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bthdef/ns-bthdef-bth_device_info)

[BTH_DEVICE_INFO_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_device_info_list)