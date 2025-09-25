## Description

The AcxObjectBagRetrieveBlob function retrieves a blob value from an existing, initialized AcxObjectBag that contains values.

## Parameters

### `ObjectBag`

An initialized ObjectBag ACX object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `ValueName`

The name of the value that will be used to access the value.

### `ValueAttributes`

Optional WDF_OBJECT_ATTRIBUTES that can be used to define additional ValueAttributes.

### `Value`

The Value to be retrieved from the ObjectBag.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

This example shows the use of AcxObjectBagRetrieveBlob.

```cpp
    WDFMEMORY vendorPropertiesBlock = NULL;
    PVOID vendorPropertiesBuffer = NULL;
    size_t vendorPropertiesSize = 0;
    NTSTATUS status = STATUS_NOT_FOUND;

    PAGED_CODE();

    //
    // Retrieve the vendor blob from the CircuitProperties object bag.
    //
    RETURN_NTSTATUS_IF_FAILED(AcxObjectBagRetrieveBlob(CircuitProperties, &VendorPropertiesBlock, NULL, &vendorPropertiesBlock));

    vendorPropertiesBuffer = WdfMemoryGetBuffer(vendorPropertiesBlock, &vendorPropertiesSize);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)