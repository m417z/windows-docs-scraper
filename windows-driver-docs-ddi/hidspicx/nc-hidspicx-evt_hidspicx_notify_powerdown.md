## Description

The **EvtHidspicxNotifyPowerdown** callback function is implemented by the client driver to receive notifications when the device is about to transition to a low-power state.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `ArmForWake`

Boolean value indicating whether the device will be armed for wake in the target state for the impending power transition.

## Return value

[**NTSTATUS**](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) indicating whether preparation for the power transition was successful or not. This method is not expected to fail at runtime, and may result in a failure of the device by HidSpiCx.

## Remarks

The client driver is expected to implement and provide a callback which HidSpiCx will use to notify the client of an impending power down. The purpose of this callback is to allow the class extension to instruct the client to stop processing interrupts from the device, as the device is about to enter a low-power state. The client should not resume processing interrupts until a callback to the client's D0Entry WDF callback has occurred.

The purpose of this function is to avoid the case when entering a sleep state where the class extension sends a `SET_POWER SLEEP` command to the device, and the device asserts interrupt to wake before the Dx IRP is completed by both the class extension and client driver. Without an additional callback instructing the client to stop hardware processing of interrupts, the hardware would issue a SPI read in response to a wake interrupt, which would violate the protocol requiring the host to first send a `SET_POWER ON` command before processing interrupts from the device.

This function will be called by the class extension at passive IRQL, and the client should not return until interrupt processing has ceased.

Whether or not the device will be armed for wake at the bus level is provided to the client as a convenience, allowing the client driver to avoid monitoring for `WAIT_WAKE` commands if it is not a bus driver.

## See also

[Device Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states)

[Device Low-Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-sleeping-states)