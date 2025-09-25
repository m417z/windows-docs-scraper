# WdfDpcCancel function

## Description

[Applies to KMDF only]

The **WdfDpcCancel** method attempts to cancel the execution of a DPC object's scheduled [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback function.

## Parameters

### `Dpc` [in]

A handle to a framework DPC object.

### `Wait` [in]

A Boolean value that, if **TRUE**, indicates that the **WdfDpcCancel** method will not return until the DPC object's [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback function is either canceled or finishes executing. If **FALSE**, the **WdfDpcCancel** method returns immediately.

## Return value

**WdfDpcCancel** returns **TRUE** if the specified DPC object's [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback function was in the system's DPC queue. The method returns **FALSE** if the callback function was not in the DPC queue, either because the callback function was executing or because it had finished executing.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If the specified DPC object's [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback function is in the system's DPC queue, it is removed from the queue. If the *EvtDpcFunc* function is not in the queue, it is either executing or has finished executing.

If the *Wait* parameter is **TRUE**, **WdfDpcCancel** must be called at IRQL = PASSIVE_LEVEL. If the *Wait* parameter is **FALSE**, **WdfDpcCancel** can be called at any IRQL.

#### Examples

The following code example cancels the execution of the callback function that is associated with the DPC object that the code example in the [WdfDpcCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpccreate) topic created.

```cpp
WdfDpcCancel(
             PDevExt->CompleteWriteDpc,
             TRUE
             );
```

## See also

[EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc)