# WdfInterruptQueueDpcForIsr function

## Description

[Applies to KMDF and UMDF]

The **WdfInterruptQueueDpcForIsr** method queues a framework interrupt object's [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function for execution.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

## Return value

**WdfInterruptQueueDpcForIsr** returns **TRUE** if it successfully queues the interrupt object's [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function. The method returns **FALSE** if the callback function was previously queued and has not executed.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Drivers typically call **WdfInterruptQueueDpcForIsr** from within an [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function.

An interrupt object's [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function can be queued only once before it executes. Therefore, if a call to **WdfInterruptQueueDpcForIsr** succeeds, subsequent calls will return **FALSE** until the framework dequeues the [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function.

The [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback will run on the processor that enqueued it. If your driver calls **WdfInterruptQueueDpcForIsr** to queue another DPC while an [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function is already dequeued or running, the second [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback might even run before the first one completes.

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

In KMDF 1.11 and later, a driver can call **WdfInterruptQueueDpcForIsr** from a passive-level ISR. Note that a driver can register a work item or a DPC but not both.

#### Examples

The following code example shows how an [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function should queue an [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function.

```cpp
BOOLEAN
MyEvtInterruptIsr(
    IN WDFINTERRUPT Interrupt,
    IN ULONG  MessageID
    )
{
    BOOLEAN queueDpcSuccess;

    //
    // Save interrupt information for the
    // EvtInterruptDpc function.
    //
...
    //
    // Queue the EvtInterruptDpc function.
    //
    queueDpcSuccess = WdfInterruptQueueDpcForIsr(Interrupt);
...
}
```

## See also

[EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc)

[EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr)

[WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate)