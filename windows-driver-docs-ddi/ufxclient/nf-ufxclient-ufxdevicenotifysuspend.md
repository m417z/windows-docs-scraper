# UfxDeviceNotifySuspend function

## Description

Notifies UFX about a USB bus suspend event.

## Parameters

### `UfxDevice` [in]

A handle to a UFX device object that the driver created by calling [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).

## Remarks

The client driver calls **UfxDeviceNotifySuspend** when it receives a bus suspend event. The default endpoint should be reset on a bus suspend. The device should move to a low power mode.

The client driver typically calls **UfxDeviceNotifySuspend** from its [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function. The following example shows how to handle a suspend event.

```
    case DeviceEventSuspend:
        if (!ControllerContext->Suspended) {
            ControllerContext->Suspended = TRUE;
            UfxDeviceNotifySuspend(ControllerContext->UfxDevice);
        }
        break;

```