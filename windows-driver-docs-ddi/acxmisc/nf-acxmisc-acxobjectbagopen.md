## Description

The function AcxObjectBagOpen opens an existing, initialized AcxObjectBag.

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

This example shows the use of ACX_OBJECTBAG_CONFIG.

```cpp
        GUID                    uniqueId = { 0 };
        UNICODE_STRING          uniqueIdStr = { 0 };
        UNICODE_STRING          pnpDeviceId = { 0 };
        ACX_OBJECTBAG_CONFIG    objBagCfg;

        DECLARE_CONST_ACXOBJECTBAG_SYSTEM_PROPERTY_NAME(UniqueID);

        ACX_OBJECTBAG_CONFIG_INIT(&objBagCfg);
        objBagCfg.Handle = CircuitConfig->CompositeProperties;
        objBagCfg.Flags |= AcxObjectBagConfigOpenWithHandle;

        WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
        ACXOBJECTBAG objBag = NULL;

        RETURN_NTSTATUS_IF_FAILED(AcxObjectBagOpen(&attributes, &objBagCfg, &objBag));
        auto objBag_free = scope_exit([&objBag]() {
            WdfObjectDelete(objBag);
            });

        RETURN_NTSTATUS_IF_FAILED(AcxObjectBagRetrieveGuid(objBag, &UniqueID, &uniqueId));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)