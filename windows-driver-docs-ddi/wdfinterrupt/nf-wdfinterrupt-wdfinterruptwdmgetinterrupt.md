# WdfInterruptWdmGetInterrupt function

## Description

[Applies to KMDF only]

The **WdfInterruptWdmGetInterrupt** method returns a pointer to the WDM interrupt object that is associated with a specified framework interrupt object.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

## Return value

The **WdfInterruptWdmGetInterrupt** method returns a pointer to a [KINTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure. This method returns **NULL** if it is called before the driver's [EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable) callback function is called or after the driver's [EvtInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_disable) callback function returns.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The pointer that the **WdfInterruptWdmGetInterrupt** method returns is valid until the driver's [EvtInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_disable) callback function returns.

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

#### Examples

The following code example obtains a pointer to the KINTERRUPT structure that is associated with a specified framework interrupt object.

```cpp
PKINTERRUPT  wdmInterrupt;

wdmInterrupt = WdfInterruptWdmGetInterrupt(Interrupt);
```

## See also

[KINTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)