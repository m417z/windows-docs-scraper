# MbbDeviceSetWakeCapabilities function

## Description

The **MbbDeviceSetWakeCapabilities** method sets the wake capabilities for a MBBCx device.

## Parameters

### `Device`

The WDFDEVICE object the driver previously obtained from a call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `Capabilities`

A pointer to a driver-allocated and initialized [**MBB_DEVICE_WAKE_CAPABILITIES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ns-mbbcx-_mbb_device_wake_capabilities) structure.

## Remarks

The client driver typically calls this method from within [*EVT_DEVICE_PREPARE_HARDWARE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware).

## See also