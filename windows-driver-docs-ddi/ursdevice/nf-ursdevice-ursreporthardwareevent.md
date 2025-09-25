# UrsReportHardwareEvent function

## Description

Notifies the USB dual-role class extension about a new hardware event.

## Parameters

### `Device` [in]

A handle to the framework device object that the client driver retrieved in the previous call to [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `HardwareEvent` [in]

A [URS_HARDWARE_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/urstypes/ne-urstypes-_urs_hardware_event)-type value that indicates the type of event that occurred.

## Remarks

Before reporting any hardware events, the client driver for the dual-role controller must indicate to the class extension that the driver supports hardware events by calling [UrsSetHardwareEventSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-urssethardwareeventsupport).

The client driver cannot pass **UrsHardwareEventNone** as the *HardwareEvent* parameter value. That value is reserved for internal use.

The client driver must call this method to report any hardware event, such as ID-pin interrupts. Typically, in the driver's implementation of the [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback, the driver reads the ID-pin state and reports the event to the class extension by calling this method.

## See also

- [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)
- [URS_HARDWARE_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/urstypes/ne-urstypes-_urs_hardware_event)
- [UrsSetHardwareEventSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-urssethardwareeventsupport)
- [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr)