# IOCTL_NFCRM_SET_RADIO_STATE IOCTL

## Description

This IOCTL is used by the radio management application or service to set the radio power state of the proximity device. The MediaRadioOn field is used to indicate the request power state. When the proximity radio power state is disabled, the driver should disable the proximity device interfaces (GUID_DEVINTERFACE_NFP and GUID_DEVINTERFACE_SMARTCARD_READER interfaces) and disable the P2P and reader/writer modes of the device. If the proximity radio power state is enabled, the driver should enable the proximity device interfaces and enable P2P and reader/writer modes of the controller. For more information about optimizing power modes on this device, see [NFC Power Management](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-power-management).

## Parameters

### Major code

### Input buffer

 [NFCRM_SET_RADIO_STATE structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcradiodev/ns-nfcradiodev-_nfcrm_set_radio_state)

### Input buffer length

sizeof(NFCRM_SET_RADIO_STATE)

### Output buffer

None

### Output buffer length

None

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to **STATUS_SUCCESS** if the request is successful. Possible error codes are:

| Return Code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_STATE** | This code is returned when the device is already in the proximity radio power state that is being set by the client. |

## Remarks

The **STATUS_INVALID_PARAMETER** return code is no longer required. A bug was discovered in Windows 10 build 10240, that Windows would send a non-null output parameter with this IOCTL. This bug was fixed in later versions of Windows. To simplify code, drivers can ignore the output parameters in all versions of Windows 10.