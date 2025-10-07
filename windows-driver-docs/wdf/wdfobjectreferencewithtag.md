# WdfObjectReferenceWithTag macro

\[Applies to KMDF and UMDF\]

The **WdfObjectReferenceWithTag** macro increments the reference count for a specified framework object and assigns the driver's current file name and line number to the reference. The macro also assigns a tag value to the reference.

## Parameters

*Handle* \[in\]
A handle to a framework object.

*Tag* \[in\]
A driver-defined value that the framework stores as an identification tag for the object reference.

## Return value

None.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If your driver calls **WdfObjectReferenceWithTag** to increment a reference count, the driver must call [**WdfObjectDereferenceWithTag**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereferencewithtag) to decrement the count.

Calling [**WdfObjectReferenceActual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectreferenceactual) or **WdfObjectReferenceWithTag** instead of [**WdfObjectReference**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference) provides additional information (tag value, line number, and file name) to Microsoft debuggers. **WdfObjectReferenceActual** allows your driver to specify the line number and file name, while **WdfObjectReferenceWithTag** uses the driver's current line number and file name.

You can view the tag, line number, and file name values by using the **!wdftagtracker** debugger extension. The debugger extension displays the tag value as both a pointer and a series of characters. For more about debugger extensions, see [Debugging a KMDF Driver](https://learn.microsoft.com/windows-hardware/drivers/debugger/kernel-mode-driver-framework-debugging).

For more information about object reference counts, see [Framework Object Life Cycle](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-life-cycle).

## Examples

The following code example increments an object's reference count and assigns a tag value to the reference.

```cpp
WdfObjectReferenceWithTag(
                          object,
                          pTag
                          );
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

## See also

[**WdfObjectReference**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference)

