# IoCancelIrp function

## Description

The **IoCancelIrp** routine sets the cancel bit in a given IRP and calls the cancel routine for the IRP if there is one.

## Parameters

### `Irp` [in]

A pointer to the IRP to be canceled.

## Return value

**IoCancelIrp** returns **TRUE** if the IRP had a cancel routine and this routine was called. Otherwise, it returns **FALSE**. In either case, the IRP's cancel bit is set to **TRUE**. For more information, see Remarks.

## Remarks

If the IRP has a cancel routine, **IoCancelIrp** sets the cancel bit and calls the cancel routine.

If *Irp*->**CancelRoutine** is **NULL**, and therefore the IRP is not cancelable, **IoCancelIrp** sets the IRP's cancel bit and returns **FALSE**. The IRP should be canceled at a later time when it becomes cancelable.

If a driver that does not own the IRP calls **IoCancelIrp**, the results are unpredictable. The IRP might be completed with a successful status even though its cancel bit was set.

An intermediate driver should not arbitrarily call **IoCancelIrp** unless that driver created the IRP passed in the call. Otherwise, the intermediate driver might cancel an IRP that some higher-level driver is tracking for purposes of its own.

## See also

[IoSetCancelRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcancelroutine)