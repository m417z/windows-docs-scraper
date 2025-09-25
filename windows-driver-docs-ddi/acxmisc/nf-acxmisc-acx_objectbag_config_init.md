## Description

The ACX_OBJECTBAG_CONFIG_INIT function initializes an [ACX_OBJECTBAG_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/ns-acxmisc-acx_objectbag_config) structure.

## Parameters

### `Config`

A pointer to the [ACX_OBJECTBAG_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/ns-acxmisc-acx_objectbag_config) structure that will be initialized.

## Remarks

### Example

This example shows the use of ACX_OBJECTBAG_CONFIG_INIT.

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

        RETURN_NTSTATUS_IF_FAILED(RtlStringFromGUID(uniqueId, &uniqueIdStr));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)