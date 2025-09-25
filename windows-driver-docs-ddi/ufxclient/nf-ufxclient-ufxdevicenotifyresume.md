# UfxDeviceNotifyResume function

## Description

Notifies UFX about a USB bus resume event.

## Parameters

### `UfxDevice` [in]

A handle to a UFX device object that the driver created by calling [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

## Remarks

The client driver calls **UfxDeviceNotifyResume** when it receives a bus resume event. The controller should return to the same state it was in at the time of the bus resume event.

The client driver typically calls **UfxDeviceNotifyResume** from its [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function. The following example shows how to handle a resume event.

```
    case DeviceEventWakeUp:
        if (ControllerContext->Suspended) {
            ControllerContext->Suspended = FALSE;
            UfxDeviceNotifyResume(ControllerContext->UfxDevice);
        }
        break;

```