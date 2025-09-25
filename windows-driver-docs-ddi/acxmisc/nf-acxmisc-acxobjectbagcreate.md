## Description

The AcxObjectBagCreate function creates a new AcxObjectBag.

## Parameters

### `Attributes`

Additional Attributes defined using a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that are used to set various object's values: cleanup and destroy callbacks, context type, and to specify its parent object.

### `Config`

A pointer to the initialized [ACX_OBJECTBAG_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/ns-acxmisc-acx_objectbag_config) structure.

### `ObjectBag`

An initialized ObjectBag ACX object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

This example shows the use of AcxObjectBagCreate.

```cpp
    DECLARE_CONST_UNICODE_STRING(I1Str,    L"Value_I1");

    // Create a simple object.
    ACX_OBJECTBAG_CONFIG_INIT(&cfg1);
    WDF_OBJECT_ATTRIBUTES_INIT(&attr);
    attr.ParentObject = WdfGetDriver();

    status = AcxObjectBagCreate(&attr, &cfg1, &bag1);
    if (!NT_SUCCESS(status))
    {
        ASSERT(FALSE);
        goto exit;
    }

    // Add something to the object bag
    status = AcxObjectBagAddI1(bag1, &I1Str, cValue);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)