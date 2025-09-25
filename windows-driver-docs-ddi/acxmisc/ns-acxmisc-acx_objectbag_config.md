## Description

The ACX_OBJECTBAG_CONFIG structure defines the configuration for an AcxObjectBag.

## Members

### `Size`

The length, in bytes, of this structure.

### `Flags`

Bitwise OR of [ACX_OBJECTBAG_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/ne-acxmisc-acx_objectbag_config_flags) that is used to configure the object bag.

### `ParentKey`

The ParentKey of the ObjectBag.

### `Name`

The name of the ObjectBag that is used to access it.

### `Handle`

The ObjectBag handle that is used to access the object bag.

## Remarks

### Example

This example shows the use of ACX_OBJECTBAG_CONFIG.

```cpp
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