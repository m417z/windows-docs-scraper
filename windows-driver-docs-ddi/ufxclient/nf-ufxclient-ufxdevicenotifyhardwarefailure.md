# UfxDeviceNotifyHardwareFailure function

## Description

Notifies UFX about a non-recoverable hardware failure in the controller.

## Parameters

### `UfxDevice` [in]

A handle to a UFX device object that the driver created by calling [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

### `HardwareFailureContext` [in, optional]

Optional pointer to a client driver-defined [UFX_HARDWARE_FAILURE_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxbase/ns-ufxbase-_ufx_hardware_failure_context) structure containing controller-specific information about the hardware failure.

## Remarks

The client driver calls **UfxDeviceNotifyHardwareFailure** when the controller has entered a non-recoverable hardware failure (such as PHY lockup). UFX can try resetting the controller to see if the controller can be recovered. The following example shows the syntax for the call:

```
    UfxDeviceNotifyHardwareFailure(
        ControllerContext->UfxDevice,
        (PUFX_HARDWARE_FAILURE_CONTEXT) HardwareFailureContext);

```