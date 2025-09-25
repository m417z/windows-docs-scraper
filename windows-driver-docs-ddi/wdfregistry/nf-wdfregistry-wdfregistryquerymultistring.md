# WdfRegistryQueryMultiString function

## Description

[Applies to KMDF and UMDF]

The **WdfRegistryQueryMultiString** method retrieves the strings that are currently assigned to a specified multi-string registry value, creates a framework string object for each string, and adds each string object to a specified [object collection](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-collections).

## Parameters

### `Key` [in]

A handle to a registry-key object that represents an opened registry key.

### `ValueName` [in]

A pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains a value name.

### `StringsAttributes` [in, optional]

A pointer to a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that contains object attributes for each new string object. This parameter is optional and can be WDF_NO_OBJECT_ATTRIBUTES.

### `Collection` [in]

A handle to a driver-supplied framework collection object.

## Return value

**WdfRegistryQueryMultiString** returns STATUS_SUCCESS if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | [WdfRegistryQueryMultiString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerymultistring) was not called at IRQL = PASSIVE_LEVEL. |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was specified. |
| **STATUS_INSUFFICIENT_RESOURCES** | A string object could not be allocated. |
| **STATUS_ACCESS_DENIED** | The driver did not open the registry key with KEY_QUERY_VALUE, KEY_READ, or KEY_ALL_ACCESS access. |
| **STATUS_OBJECT_TYPE_MISMATCH** | The data type of the registry value that the *ValueName* parameter specified was not REG_MULTI_SZ. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The registry value was not available. |
| **STATUS_RESOURCE_DATA_NOT_FOUND** | The registry value exists under the specified key, but is empty. |

For a list of other return values that the **WdfRegistryQueryMultiString** method might return, see [Framework Object Creation Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-creation-errors).

This method also might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Before your driver calls **WdfRegistryQueryMultiString**, it must call [WdfCollectionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectioncreate) to create a collection object.

If the caller does not provide a *StringsAttributes* parameter, any WDFSTRING objects created by the framework are by default parented to the WDFDRIVER.

After **WdfRegistryQueryMultiString** returns, the driver can call [WdfCollectionGetCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectiongetcount) to obtain the number of retrieved strings and [WdfCollectionGetItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectiongetitem) to obtain string objects from the collection.

If the collection contains objects before the driver calls the **WdfRegistryQueryMultiString** method, the method does not remove those objects or change their index values. The new objects are appended to the end of the collection.

To obtain a string from a string object, the driver can call [WdfStringGetUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringgetunicodestring).

For more information about registry-key objects, see [Using the Registry in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-wdf-drivers).

#### Examples

The following code example creates a collection object, initializes a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure so that the collection object will be the parent of all of the string objects that the framework creates for the collection, and retrieves the strings from a multi-string registry value. Finally, the example obtains the number of string objects that the framework added to the collection.

```cpp
WDF_OBJECT_ATTRIBUTES stringAttributes;
WDFCOLLECTION col;
NTSTATUS status;
ULONG count;
DECLARE_CONST_UNICODE_STRING(valueMultiSz, VALUE_MULTI_SZ);

status = WdfCollectionCreate(
                             NULL,
                             &col
                             );
ASSERT(NT_SUCCESS(status));

WDF_OBJECT_ATTRIBUTES_INIT(&stringAttributes);
stringAttributes.ParentObject = col;

status = WdfRegistryQueryMultiString(
                                     Key,
                                     &valueMultiSzEmpty,
                                     &stringAttributes,
                                     col
                                     );

count = WdfCollectionGetCount(col);
```

## See also

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WdfCollectionCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectioncreate)

[WdfCollectionGetCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectiongetcount)

[WdfCollectionGetItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectiongetitem)

[WdfRegistryQueryMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerymemory)

[WdfRegistryQueryString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryquerystring)

[WdfRegistryQueryULong](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryulong)

[WdfRegistryQueryUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryunicodestring)

[WdfRegistryQueryValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfregistry/nf-wdfregistry-wdfregistryqueryvalue)

[WdfStringGetUnicodeString](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/nf-wdfstring-wdfstringgetunicodestring)