# WdfObjectReferenceActual function

## Description

[Applies to KMDF and UMDF]

The **WdfObjectReferenceActual** method increments the reference count for a specified framework object and assigns a tag value, line number, and file name to the reference.

## Parameters

### `Handle` [in]

A handle to a framework object.

### `Tag` [in, optional]

A driver-defined value that the framework stores as an identification tag for the object reference.

### `Line` [in]

A numeric value that represents a line number in a driver source file.

### `File` [in]

A pointer to a null-terminated constant character string that represents the name of a driver source file. This parameter is optional and can be **NULL**.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

If your driver calls **WdfObjectReferenceActual** to increment a reference count, the driver must call [WdfObjectDereferenceActual](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdereferenceactual) to decrement the count.

Calling **WdfObjectReferenceActual** or [WdfObjectReferenceWithTag](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreferencewithtag) instead of [WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference) provides additional information (tag value, line number, and file name) to Microsoft debuggers. **WdfObjectReferenceActual** allows your driver to specify the line number and file name, while **WdfObjectReferenceWithTag** uses the driver's current line number and file name.

You can view the tag, line number, and file name values by using the **!wdftagtracker** debugger extension. The debugger extension displays the tag value as both a pointer and a series of characters. For more about debugger extensions, see [Debugging a KMDF Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/debugging-driver-installation).

For more information about object reference counts, see [Framework Object Life Cycle](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-life-cycle).

For more information about the cleanup rules for a framework object hierarchy, see [Framework Object Life Cycle](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-life-cycle).

#### Examples

The following code example increments an object's reference count and assigns a tag value, line number, and file name to the reference.

```cpp
WdfObjectReferenceActual(
                         object,
                         pTag,
                         line,
                         FILE_NAME
                         );
```

## See also

[WdfObjectReference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectreference)