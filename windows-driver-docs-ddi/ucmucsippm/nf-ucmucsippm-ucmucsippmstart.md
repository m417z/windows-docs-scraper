# UcmUcsiPpmStart function

## Description

Instructs the UcmUcsiCx class extension to start sending requests to the client driver.

## Parameters

### `PpmObject` [in]

A handle to a Platform Policy Manager (PPM) object that the client driver received in the previous call to [**UcmUcsiPpmCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmucsippm/nf-ucmucsippm-ucmucsippmcreate).

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

**UcmUcsiPpmStart** indicates that the client driver is now ready to receive request from the class extension. Upon this call, the class extension starts OS Policy Manager (OPM) and Command Handler state machines.

The client driver must call **UcmUcsiPpmStart** after it had called UcmUcsiPpmStop for error recovery.

This DDI starts the operations that the class extension needs to perform to initialize the OPM and Command Handler state machines. The client driver must call **UcmUcsiPpmStart** to notify UcmUcsiCx that the driver is ready to receive the IOCTL requests. We recommend that you make this call either from the [**EVT_WDF_DEVICE_PREPARE_HARDWARE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware) callback function, or after the system calls this callback.

Attempting to start the PPM after it has already started leads to an error condition.

After the client calls **UcmUcsiPpmStart**, the class extension sends a number of commands to the PPM firmware in order to get PPM and connector capabilities and their statuses. Due to a high number interactions with the firmware, we strongly recommend UcmUcsiCx client implementors call this DDI once during startup and not on resume from a low power state, such as D0Entry callback. This is especially true when the client implements S0 idling.

## See also