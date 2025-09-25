## Description

The AcxObjectBagRetrieveI2 function retrieves an int two byte I2 (SHORT) value from an existing, initialized AcxObjectBag that contains values.

## Parameters

### `ObjectBag`

An initialized ObjectBag ACX object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `ValueName`

The name of the value that will be used to access the value.

### `Value`

The Value to be retrieved from the ObjectBag.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

This example shows the use of AcxObjectBagRetrieveI2.

```cpp
    ACXOBJECTBAG objBag     = NULL;
    SHORT        i2Value    = 0;

    //Initialize an object bag configuration
    ACX_OBJECTBAG_CONFIG objBagCfg;
    ACX_OBJECTBAG_CONFIG_INIT(&objBagCfg);

    // Set the WDF attributes, and create an object bag
    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    attributes.ParentObject = Circuit;
    RETURN_NTSTATUS_IF_FAILED(AcxObjectBagCreate(&attributes, &objBagCfg, &objBag));

    // Enable deletion of the object bag when the function completes and goes out of scope
    auto objBag_scope = scope_exit([&objBag]() {
        if (objBag != NULL)
        {
            WdfObjectDelete(objBag);
        }
    });

    //Create Properties and add them to an object bag
    DECLARE_CONST_ACXOBJECTBAG_DRIVER_PROPERTY_NAME(VendorX, TestI2);

    i2Value = 1;
    RETURN_NTSTATUS_IF_FAILED(AcxObjectBagAddI2(objBag, &TestI2, i2Value));

    // Retrieve the value from the object bag
    i2Value = 0;
    RETURN_NTSTATUS_IF_FAILED(AcxObjectBagRetrieveI2(objBag, &TestI2, &i2Value));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)