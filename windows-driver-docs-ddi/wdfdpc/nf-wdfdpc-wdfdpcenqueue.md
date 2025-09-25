# WdfDpcEnqueue function

## Description

[Applies to KMDF only]

The **WdfDpcEnqueue** method schedules the execution of a DPC object's [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback function.

## Parameters

### `Dpc` [in]

A handle to a framework DPC object.

## Return value

**WdfDpcEnqueue** returns **TRUE** if it successfully adds the specified DPC object to the system's DPC queue. Otherwise, the method returns **FALSE**.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The **WdfDpcEnqueue** method adds the specified DPC object to the system's DPC queue, if it is not already in the queue. (If the DPC object was already in the queue, the method returns **FALSE**.) When the system is not executing higher-priority tasks, it removes the DPC object from the queue and calls the object's [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback function.

After the callback function executes, a subsequent call to **WdfDpcEnqueue** will add the DPC object back into the DPC queue.

For more information about using DPC objects, see [Servicing an Interrupt](https://learn.microsoft.com/windows-hardware/drivers/wdf/servicing-an-interrupt).

#### Examples

The following code example schedules the execution of the callback function that is associated with a DPC object. The example uses the **WdfDpcEnqueue** method's return value as the containing function's return value. The [WdfDpcCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpccreate) code example shows how the DPC object was created.

```cpp
return WdfDpcEnqueue(PDevExt->CompleteWriteDpc);
```

## See also

[EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc)

[WdfDpcCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpccreate)