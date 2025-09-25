# EVT_SERCX2_SET_WAIT_MASK callback function

## Description

The *EvtSerCx2SetWaitMask* event callback function is called by version 2 of the serial framework extension (SerCx2) to configure the serial controller to monitor a set of hardware events that are specified by a wait mask.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller. The serial controller driver created this object in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. For more information, see [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice).

### `Request` [in]

A WDFREQUEST handle to the framework request object that represents the [IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask) request.

### `WaitMask` [in]

The new wait mask. For more information, see Remarks.

## Remarks

Your serial controller driver can, as an option, implement this function. If implemented, the driver registers the function in the call to the [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice) method that finishes the initialization of the framework device object for the serial controller.

When SerCx receives an [IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask) request from a client, the request handler in SerCx2 calls the *EvtSerCx2SetWaitMask* function, if it is implemented, to notify the driver that the wait mask has changed. If the wait mask is nonzero, the driver immediately starts to monitor the events in the new wait mask, and discards any old wait mask that might have been supplied in a previous *EvtSerCx2SetWaitMask* call. If the new wait mask is zero, the driver simply discards the old wait mask and ceases to monitor any wait mask events. For more information about the types of events that can be specified by a wait mask, see [SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports).

If the driver does not implement this function, SerCx2 fails all [IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask) requests with error status code STATUS_NOT_SUPPORTED.

To monitor the events in the wait mask, the *EvtSerCx2SetWaitMask* function typically enables interrupts for these events. Later, when an event in the wait mask is detected, the serial controller driver calls the [SerCx2CompleteWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2completewait) method to notify SerCx2 of the event.

The *EvtSerCx2SetWaitMask* function is responsible for completing the **IOCTL_SERIAL_SET_WAIT_MASK** request pointed to by the *Request* parameter. After the serial controller driver enables the necessary interrupts, it calls the [WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete) method and supplies, as input parameters, the *Request* parameter value and a status value to indicate whether the request was successful.

Before the serial controller driver calls **WdfRequestComplete** to complete the request, the driver must finish any calls to **SerCx2CompleteWait** that might be still be pending due to events in the old wait mask.

Initially, after a client opens a logical connection to the serial port and before the first *EvtSerCx2SetWaitMask* call, the wait mask is effectively zero, and the serial controller driver is not monitoring any [SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports) events.

SerCx2 fails an **IOCTL_SERIAL_SET_WAIT_MASK** request that has a wait mask that includes any of the following [SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports) event flags:

* SERIAL_EV_PERR
* SERIAL_EV_RING
* SERIAL_EV_RXFLAG

Thus, the wait mask supplied to your *EvtSerCx2SetWaitMask* function never contains any of the event flags in the preceding list.

If implemented, your *EvtSerCx2SetWaitMask* function should support the following event flags:

* SERIAL_EV_CTS
* SERIAL_EV_BREAK
* SERIAL_EV_ERR

Also, if the serial controller has a *data set ready* (DSR) signal line, the *EvtSerCx2SetWaitMask* function should support SERIAL_EV_DSR. As an option, a driver can support any of the other event flags described in [SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports). If the wait mask specifies an event that the driver does not support, the *EvtSerCx2SetWaitMask* function should fail the request and set the status value in the request to STATUS_INVALID_PARAMETER.

#### Examples

To define an *EvtSerCx2SetWaitMask* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2SetWaitMask* callback function that is named `MySetWaitmask`, use the **EVT_SERCX2_SET_WAIT_MASK** function type, as shown in this code example:

```cpp
EVT_SERCX2_SET_WAIT_MASK  MySetWaitmask;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
VOID
  MySetWaitmask(
    WDFDEVICE  Device,
    WDFREQUEST Request,
    ULONG WaitMask
    )
  {...}
```

The **EVT_SERCX2_SET_WAIT_MASK** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_SET_WAIT_MASK** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[IOCTL_SERIAL_SET_WAIT_MASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ni-ntddser-ioctl_serial_set_wait_mask)

[SERIAL_EV_XXX](https://learn.microsoft.com/windows-hardware/drivers/serports/peripheral-drivers-for-devices-on-sercx2-managed-serial-ports)

[SerCx2CompleteWait](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2completewait)

[SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice)

[WdfRequestComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestcomplete)