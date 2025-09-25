# EVT_POS_CX_DEVICE_REMOTE_RELEASE callback function

## Description

The
EVT_POS_CX_DEVICE_REMOTE_RELEASE callback is called whenever the device is released and left
with no owner and allows the driver to do additional work. This callback is typically only used with network connected devices that require additional logic for handling ownership transitions.

[EVT_POS_CX_DEVICE_REMOTE_CLAIM](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nc-poscx-evt_pos_cx_device_remote_claim) and *EVT_POS_CX_DEVICE_REMOTE_RELEASE* add support for remote devices that handle their own claim
semantics.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `deviceInterfaceTag` [in]

An identifier used to specify which interface is being released in a multi-function device. For a single-interface device, this value should be 0.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS or another status value for which NT_SUCCESS(status) equals TRUE.

If the driver is unable to complete the remote release transaction, it should return STATUS_ACCESS_DENIED so that the failure will bubble up to the application.

## See also

[EVT_POS_CX_DEVICE_REMOTE_CLAIM](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nc-poscx-evt_pos_cx_device_remote_claim)