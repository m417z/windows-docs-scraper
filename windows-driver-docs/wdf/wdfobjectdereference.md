# WdfObjectDereference macro

\[Applies to KMDF and UMDF\]

The **WdfObjectDereference** macro decrements the reference count for a specified framework object.

## Parameters

*Handle* \[in\]
A handle to a framework object.

## Return value

None.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If the object's reference count becomes zero, the object might be deleted before **WdfObjectDereference** returns.

A driver can call **WdfObjectDereference** only if it has previously called [**WdfObjectReference**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference).

Instead of calling **WdfObjectDereference**, a driver can call [**WdfObjectDereferenceWithTag**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereferencewithtag) or [**WdfObjectDereferenceActual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdereferenceactual).

For more information about object reference counts, see [Framework Object Life Cycle](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-life-cycle).

## Examples

The following code example decrements an object's reference count.

```cpp
WdfObjectDereference(Object);
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
| DDI compliance rules | [**DriverCreate**](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-drivercreate), [**MemAfterReqCompletedIntIoctlA**](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-memafterreqcompletedintioctla), [**MemAfterReqCompletedIoctlA**](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-memafterreqcompletedioctla), [**MemAfterReqCompletedReadA**](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-memafterreqcompletedreada), [**MemAfterReqCompletedWriteA**](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-memafterreqcompletedwritea), [**wdfioqueuefindrequestfailed**](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueuefindrequestfailed), [**wdfioqueueretrievefoundrequest**](https://learn.microsoft.com/windows-hardware/drivers/devtest/kmdf-wdfioqueueretrievefoundrequest) |

## See also

[**WdfObjectDereferenceActual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdereferenceactual)

[**WdfObjectDereferenceWithTag**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereferencewithtag)

[**WdfObjectReference**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference)