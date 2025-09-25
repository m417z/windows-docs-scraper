## Description

The AcxObjectBagRetrieveUI1 function retrieves an unsigned int one byte (UCHAR) UI1 value from an existing, initialized AcxObjectBag that contains values.

## Parameters

### `ObjectBag`

An initialized ObjectBag ACX object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `ValueName`

The name of the value that will be used to access the value.

### `Value`

The UCHAR Value to be retrieved from the ObjectBag.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

This example shows the use of AcxObjectBagRetrieveUI1.

```cpp
    ACXOBJECTBAG objBag     = NULL;
    UCHAR        ui1Value   = 0;

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
    DECLARE_CONST_ACXOBJECTBAG_DRIVER_PROPERTY_NAME(VendorX, TestUI1);

    ui1Value = 1;
    RETURN_NTSTATUS_IF_FAILED(AcxObjectBagAddUI1(objBag, &TestUI1, ui1Value));

    // Retrieve the value from the object bag
    ui1Value = 0;
    RETURN_NTSTATUS_IF_FAILED(AcxObjectBagRetrieveUI1(objBag, &TestUI1, &ui1Value));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)