# EVT_POS_CX_DEVICE_REMOTE_RETAIN callback function

## Description

The
EVT_POS_CX_DEVICE_REMOTE_RETAIN callback is called whenever PosCx attempts to hold onto a claim
on a network device and allows the driver to do additional work. This callback is typically only used with network connected devices that require additional logic for handling ownership transitions.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `deviceInterfaceTag` [in]

An identifier used to specify which interface is being retained in a multi-function device. For a single-interface device, this value should be 0.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS or another status value for which NT_SUCCESS(status) equals TRUE.

If the driver is unable to complete the remote retain transaction, it should return STATUS_ACCESS_DENIED so that the failure will bubble up to the application.