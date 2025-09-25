# WdfInterruptGetDevice function

## Description

[Applies to KMDF and UMDF]

The **WdfInterruptGetDevice** method returns a handle to the framework device object that is associated with a specified framework interrupt object.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

## Return value

**WdfInterruptGetDevice** returns a handle to a framework device object.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

#### Examples

The following code example shows how an [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function can obtain a pointer to driver-defined context space for the device object that an interrupt object belongs to.

```cpp
BOOLEAN
MyEvtInterruptIsr(
    IN WDFINTERRUPT Interrupt,
    IN ULONG  MessageID
    )
{
    PDEVICE_EXTENSION  devExt;

    devExt = GetMyDeviceContext(WdfInterruptGetDevice(Interrupt));
...
}
```

## See also

[EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr)