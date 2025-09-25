# EVT_SERCX_WAITMASK callback function

## Description

The *EvtSerCxWaitmask* event callback function configures the serial controller to monitor the events in a wait mask, which is a bitmask value that specifies a set of hardware events.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller.

## Return value

The *EvtSerCxWaitmask* function returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error status code.

## Remarks

The serial controller driver implements this callback function. The serial framework extension (SerCx) calls this function to notify the driver when the wait mask changes. During this call, the *EvtSerCxWaitmask* function calls the [SerCxGetWaitMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxgetwaitmask) method to get the new wait mask. The driver immediately starts to monitor the events in the new wait mask, and discards any old wait mask that might have been supplied in a previous *EvtSerCxWaitmask* call. If the new wait mask is zero, the driver simply discards the old wait mask and ceases to monitor any wait mask events.

When SerCx receives an [IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask) request from a client, the request handler in SerCx calls the *EvtSerCxWaitmask* function to set the new wait mask. For more information about the types of events that can be specified by a wait mask, see [SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports).

The *EvtSerCxWaitmask* function configures the serial controller hardware to monitor the events in the new wait mask. Typically, the function enables interrupts for these events. After configuring the hardware, the function should return immediately, without waiting for an event in the wait mask to occur.

Later, when an event in the wait mask causes an interrupt to occur, the ISR in the serial controller driver schedules a DPC function to run. This DPC function calls the [SerCxCompleteWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxcompletewait) method to notify SerCx of the event.

Initially, after a client opens a connection to the serial port and before the first *EvtSerCxWaitmask* call, the wait mask is effectively zero, and the serial controller driver is not monitoring any **SERIAL_EV_*XXX*** events.

To register an *EvtSerCxWaitmask* callback function, the controller driver calls the [SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize) method during the [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback.

#### Examples

The function type for this callback is declared in Sercx.h, as follows.

```cpp
typedef NTSTATUS
  EVT_SERCX_WAITMASK(
    __in WDFDEVICE Device
    );
```

To define an *EvtSerCxWaitmask* callback function that is named `MyEvtSerCxWaitmask`, you must first provide a function declaration that [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV) and other verification tools require, as follows.

```cpp
EVT_SERCX_WAITMASK MyEvtSerCxWaitmask;
```

Then, implement your callback function as follows.

```cpp
NTSTATUS
  MyEvtSerCxWaitmask(
    __in WDFDEVICE Device
    )
{ ... }
```

For more information about SDV requirements for function declarations, see [Declaring Functions Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask)

[IOCTL_SERIAL_WAIT_ON_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_wait_on_mask)

[SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports)

[SerCxGetWaitMask](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxgetwaitmask)

[SerCxInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxinitialize)