## Description

The AcxObjectBagAddGuid function adds Guid data to an existing, initialized AcxObjectBag.

## Parameters

### `ObjectBag`

An initialized ObjectBag ACX object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `ValueName`

The name of the value that will be used to access the value.

### `Value`

The Value to be added to the ObjectBag.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

The code below shows the use of AcxObjectBagAddGuid.

```cpp
    // Object bag
    //
    // This obj-bag config setting is shared by all composite/circuit templates.
    ACX_OBJECTBAG_CONFIG objBagCfg;
    ACX_OBJECTBAG_CONFIG_INIT(&objBagCfg);

    WDF_OBJECT_ATTRIBUTES attributes;
    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    attributes.ParentObject = AcxGetManager(NULL);

    ACXOBJECTBAG objBag = NULL;
    RETURN_NTSTATUS_IF_FAILED(AcxObjectBagCreate(&attributes, &objBagCfg, &objBag));

    // Enable deletion of the object bag when the function completes and goes out of scope
    auto objBag_scope = scope_exit([&objBag]() {
        if (objBag != NULL)
        {
            WdfObjectDelete(objBag);
        }
    });

    //
    // Add a test unsigned int 4 bytes to the object bag
    //
    RETURN_NTSTATUS_IF_FAILED(ObjBagAddTestUI4(objBag, 0));

    //
    // Add unique circuit ID to the object bag
    // This unique Id will be picked up by DSP circuit
    //
    DECLARE_CONST_ACXOBJECTBAG_SYSTEM_PROPERTY_NAME(UniqueID);
    GUID uniqueID = { 0 };
    RETURN_NTSTATUS_IF_FAILED(RtlGUIDFromString(&circuit_IDs[compositeType], &uniqueID));

    RETURN_NTSTATUS_IF_FAILED(AcxObjectBagAddGuid(objBag, &UniqueID, uniqueID));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)