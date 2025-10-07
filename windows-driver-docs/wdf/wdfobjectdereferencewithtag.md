# WdfObjectDereferenceWithTag macro

\[Applies to KMDF and UMDF\]

The **WdfObjectDereferenceWithTag** macro decrements the reference count for a specified framework object and assigns the driver's current file name and line number to the reference. This macro also assigns a tag value to the reference.

## Parameters

*Handle* \[in\]
A handle to a framework object.

*Tag* \[in\]
A driver-defined value that identifies an object reference. The tag value must match a tag value that the driver previously supplied to [**WdfObjectReferenceWithTag**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreferencewithtag).

## Return value

None.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If the object's reference count becomes zero, the object might be deleted before **WdfObjectDereferenceWithTag** returns.

Calling [**WdfObjectDereferenceActual**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdereferenceactual) or **WdfObjectDereferenceWithTag** instead of [**WdfObjectDereference**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference) provides additional information (tag string, line number, and file name) to Microsoft debuggers. **WdfObjectDereferenceActual** allows your driver to specify the line number and file name, while **WdfObjectDereferenceWithTag** uses the driver's current line number and file name.

You can view the tag, line number, and file name values by using the **!wdftagtracker** debugger extension. The debugger extension displays the tag value as both a pointer and a series of characters. For more about debugger extensions, see [Debugging a KMDF Driver](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-universal-drivers---step-by-step-lab--echo-kernel-mode-).

For more information about object reference counts, see [Framework Object Life Cycle](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-life-cycle).

## Examples

The following code example decrements an object's reference count and assigns a tag value to the reference.

```cpp
WdfObjectDereferenceWithTag(
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

[**WdfObjectDereference**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference)

[**WdfObjectReferenceWithTag**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreferencewithtag)

