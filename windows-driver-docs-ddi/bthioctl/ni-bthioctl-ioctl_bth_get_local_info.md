# IOCTL_BTH_GET_LOCAL_INFO IOCTL

## Description

The IOCTL_BTH_GET_LOCAL_INFO request returns information about the local Bluetooth system and
radio.

## Parameters

### Major code

### Input buffer

The
**AssociatedIrp.SystemBuffer** member points to a buffer for a
[BTH_LOCAL_RADIO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_local_radio_info) structure.

### Input buffer length

The length of a
[BTH_LOCAL_RADIO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_local_radio_info) structure.

### Output buffer

The
**AssociatedIrp.SystemBuffer** member points to a buffer that holds a
[BTH_LOCAL_RADIO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_local_radio_info) structure. The
buffer contains information about the local radio, including a
[BTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bthdef/ns-bthdef-bth_device_info) structure and a
[BTH_RADIO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_radio_info) structure.

### Output buffer length

The length of a
[BTH_LOCAL_RADIO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_local_radio_info) structure.

### Input/output buffer

### Input/output buffer length

### Status block

The
**Information** member of the STATUS_BLOCK structure is set to the size, in bytes, of the output
buffer.

The
**Status** member of the STATUS_BLOCK structure is always set to STATUS_SUCCESS.

## See also

[BTH_DEVICE_INFO](https://learn.microsoft.com/windows/win32/api/bthdef/ns-bthdef-bth_device_info)

[BTH_LOCAL_RADIO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_local_radio_info)

[BTH_RADIO_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ns-bthioctl-_bth_radio_info)