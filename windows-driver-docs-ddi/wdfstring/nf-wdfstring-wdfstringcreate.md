# WdfStringCreate function

## Description

[Applies to KMDF and UMDF]

The **WdfStringCreate** method creates a framework string object and optionally assigns a specified Unicode string to the object.

## Parameters

### `UnicodeString` [in, optional]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a Unicode string constant. The framework copies the string to the new framework string object. This pointer is optional and can be **NULL**.

### `StringAttributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains driver-supplied attributes for the new string object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `String` [out]

A pointer to a location that receives a handle to the new string object.

## Return value

**WdfStringCreate** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfStringCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringcreate) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_INSUFFICIENT_RESOURCES** | A string object could not be allocated. |

For a list of other return values that the **WdfStringCreate** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The default parent for framework string objects is the driver's framework driver object. However, unless the string is associated with the driver, your driver should set the **ParentObject** member of the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure to an object that represents the string's scope. Typically, strings are device-specific and their parent object should be a framework device object.

If your driver provides [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback functions for the framework string object, note that the framework calls these callback functions at IRQL = PASSIVE_LEVEL.

For more information about framework string objects, see [Using String Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-string-objects).

#### Examples

The following code example initializes a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure and then creates a framework string object.

```cpp
NTSTATUS  status;
WDFSTRING  stringHandle = NULL;
WDF_OBJECT_ATTRIBUTES  attributes;

WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
attributes.ParentObject = pDeviceContext->Device;
status = WdfStringCreate(
                         NULL,
                         &attributes,
                         &stringHandle
                         );
if (!NT_SUCCESS(status)){
    return status;
}
```

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfStringGetUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringgetunicodestring)