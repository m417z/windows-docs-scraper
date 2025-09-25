# WdfRegistryAssignMultiString function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryAssignMultiString** method assigns a set of strings to a specified value name in the registry. The strings are contained in a specified collection of framework string objects.

## Parameters

### `Key` [in]

A handle to a registry-key object that represents an opened registry key.

### `ValueName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a value name.

### `StringsCollection` [in]

A handle to a framework collection object that represents a collection of framework string objects.

## Return value

**WdfRegistryAssignMultiString** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfRegistryAssignMultiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignmultistring) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified, or the collection that the *StringsCollection* parameter specified contained no string objects. |
| **STATUS_ACCESS_DENIED** | The driver did not open the registry key with KEY_SET_VALUE access. |

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If the value name that the *ValueName* parameter specifies already exists, **WdfRegistryAssignMultiString** updates the value's data.

The framework sets the value's data type to REG_MULTI_SZ.

The object collection that *StringsCollection* specifies must contain only framework string objects.

For more information about registry-key objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example creates a collection object and two string objects, adds the string objects to the collection, and then assigns the two strings to one registry value.

```cpp
WDF_OBJECT_ATTRIBUTES attributes;
WDFCOLLECTION col = NULL;
WDFSTRING string1 = NULL, string2 = NULL;
UNICODE_STRING ustring1, ustring2, valueName;
NTSTATUS status;

status = WdfCollectionCreate(
                             WDF_NO_OBJECT_ATTRIBUTES,
                             &col
                             );
if (!NT_SUCCESS(status) {
    return status;
}

RtlInitUnicodeString(
                     &ustring1,
                     L"String1"
                     );
RtlInitUnicodeString(
                     &ustring2,
                     L"String2"
                     );
RtlInitUnicodeString(
                     &valueName,
                     L"ValueName"
                     );

WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
attributes.ParentObject = col;

status = WdfStringCreate(
                         &ustring1,
                         &attributes,
                         &string1
                         );
if (!NT_SUCCESS(status)) {
    goto exit;
}
status = WdfStringCreate(
                         &ustring2,
                         &attributes,
                         &string2
                         );
if (!NT_SUCCESS(status)) {
    goto exit;
}
status = WdfCollectionAdd(
                          col,
                          string1
                          );
if (!NT_SUCCESS(status)) {
    goto exit;
}
string1 = NULL;

status = WdfCollectionAdd(
                          col,
                          string2
                          );
if (!NT_SUCCESS(status)) {
    goto exit;
}
string2 = NULL;

status = WdfRegistryAssignMultiString(
                                      Key,
                                      &valueName,
                                      col
                                      );
if (!NT_SUCCESS(status)) {
    goto exit;
...
exit:
if (col != NULL) {
    WdfObjectDelete(col);    // This will empty the collection
                             // because the string objects are
                             // child objects of the collection object.
}
```

## See also

[RtlInitUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlinitunicodestring)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WdfCollectionAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectionadd)

[WdfCollectionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectioncreate)

[WdfObjectDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectdelete)

[WdfRegistryAssignMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignmemory)

[WdfRegistryAssignString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignstring)

[WdfRegistryAssignULong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignulong)

[WdfRegistryAssignUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignunicodestring)

[WdfRegistryAssignValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryassignvalue)

[WdfStringCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringcreate)