# WdfObjectReference macro

\[Applies to KMDF and UMDF\]

The **WdfObjectReference** macro increments the reference count for a specified framework object.

## Parameters

*Handle* \[in\]
A handle to a framework object.

## Return value

None.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If your driver calls **WdfObjectReference** to increment a reference count, the driver must call [**WdfObjectDereference**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference) to decrement the count.

Instead of calling **WdfObjectReference**, a driver can call [**WdfObjectReferenceWithTag**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreferencewithtag) or [**WdfObjectReferenceActual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectreferenceactual).

For more information about object reference counts, see [Framework Object Life Cycle](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-life-cycle).

## Examples

The following code example increments an object's reference count.

```cpp
WdfObjectReference(Object);
```

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356) |
| Minimum KMDF version | 1.0 |
| Minimum UMDF version | 2.0 |
| Header | Wdfobject.h (include Wdf.h) |
| Library | Wdf01000.sys (KMDF); WUDFx02000.dll (UMDF) |
| IRQL | <= DISPATCH_LEVEL |
| DDI compliance rules | [**DriverCreate**](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-drivercreate), [**MemAfterReqCompletedIntIoctlA**](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-memafterreqcompletedintioctla), [**MemAfterReqCompletedIoctlA**](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-memafterreqcompletedioctla), [**MemAfterReqCompletedReadA**](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-memafterreqcompletedreada), [**MemAfterReqCompletedWriteA**](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-memafterreqcompletedwritea) |

## See also

[**WdfObjectReferenceActual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectreferenceactual)

[**WdfObjectReferenceWithTag**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreferencewithtag)