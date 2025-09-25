# WdfObjectDereferenceActual function

## Description

[Applies to KMDF and UMDF]

The **WdfObjectDereferenceActual** method decrements the reference count for a specified framework object and assigns a tag value, line number, and file name to the reference*.*

## Parameters

### `Handle` [in]

A handle to a framework object.

### `Tag` [in, optional]

A driver-defined value that identifies an object reference. The tag value must match a tag value that the driver previously supplied to [WdfObjectReferenceActual](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectreferenceactual).

### `Line` [in]

A numeric value that represents a line number in a driver source file.

### `File` [in, optional]

A pointer to a null-terminated constant character string that represents the name of a driver source file. This parameter is optional and can be **NULL**.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

If the object's reference count becomes zero, the object might be deleted before **WdfObjectDereferenceActual** returns.

Calling **WdfObjectDereferenceActual** or [WdfObjectDereferenceWithTag](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereferencewithtag) instead of [WdfObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference) provides additional information (tag string, line number, and file name) to Microsoft debuggers. **WdfObjectDereferenceActual** allows your driver to specify the line number and file name, while **WdfObjectDereferenceWithTag** uses the driver's current line number and file name.

You can view the tag, line number, and file name values by using the **!wdftagtracker** debugger extension. The debugger extension displays the tag value as both a pointer and a series of characters. For more information about debugger extensions, see [Debugging a KMDF Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/debugging-driver-installation).

For more information about object reference counts and the cleanup rules for a framework object hierarchy, see [Framework Object Life Cycle](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-life-cycle).

#### Examples

The following code example decrements an object's reference count and assigns a tag value, line number, and file name to the reference.

```cpp
WdfObjectDereferenceActual(
                           object,
                           pTag,
                           line,
                           FILE_NAME
                           );
```

## See also

[WdfObjectDereference](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectdereference)

[WdfObjectReferenceActual](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectreferenceactual)