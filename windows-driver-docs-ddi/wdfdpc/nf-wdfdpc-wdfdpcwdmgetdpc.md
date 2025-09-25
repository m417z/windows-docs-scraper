# WdfDpcWdmGetDpc function

## Description

[Applies to KMDF only]

The **WdfDpcWdmGetDpc** method returns a pointer to the [KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that is associated with a specified framework DPC object.

## Parameters

### `Dpc` [in]

A handle to a framework DPC object.

## Return value

**WdfDpcWdmGetDpc** returns a pointer to the [KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that is associated with the specified framework DPC object.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

The framework creates a KDPC structure when a framework-based driver calls [WdfDpcCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpccreate) to create a DPC object.

A driver might call **WdfDpcWdmGetDpc** from within its [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback function.

The pointer that **WdfDpcWdmGetDpc** returns is valid until the framework DPC object is deleted. If the driver provides an [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) function for the framework DPC object, the pointer is valid until the callback function returns.

#### Examples

The following code example returns a pointer to the [KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure that is associated with a specified DPC object. The [WdfDpcCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpccreate) code example shows how the specified DPC object was created.

```cpp
PKDPC pWdmDpc;

pWdmDpc = WdfDpcWdmGetDpc(PDevExt->CompleteWriteDpc);
```

## See also

[EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc)

[KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[WDF_DPC_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/ns-wdfdpc-_wdf_dpc_config)

[WdfDpcCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpccreate)