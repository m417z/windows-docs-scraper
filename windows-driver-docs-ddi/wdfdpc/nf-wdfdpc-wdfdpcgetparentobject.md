# WdfDpcGetParentObject function

## Description

[Applies to KMDF only]

The **WdfDpcGetParentObject** method returns the parent object of a specified DPC object.

## Parameters

### `Dpc` [in]

A handle to a framework DPC object.

## Return value

**WdfDpcGetParentObject** returns a handle to the parent object of a specified DPC object.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A driver might call **WdfDpcGetParentObject** from within its [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback function.

#### Examples

The following code example returns a handle to the parent object of a specified DPC object. The [WdfDpcCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpccreate) code example shows how the specified DPC object was created.

```cpp
WDFDEVICE Device;

Device = WdfDpcGetParentObject(PDevExt->CompleteWriteDpc);
```

## See also

[EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc)