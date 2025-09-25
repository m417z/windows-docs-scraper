## Description

The AcxObjectBagRetrieveSizeT function retrieves a SIZE_T value from an existing, initialized AcxObjectBag.

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

```cpp
        SIZE_T                  sizeValue = 0;
        ACX_OBJECTBAG_CONFIG    objBagCfg;

        DECLARE_CONST_ACXOBJECTBAG_SYSTEM_PROPERTY_NAME(TestName);

        ACX_OBJECTBAG_CONFIG_INIT(&objBagCfg);
        objBagCfg.Handle = CircuitConfig->CompositeProperties;
        objBagCfg.Flags |= AcxObjectBagConfigOpenWithHandle;

        WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
        ACXOBJECTBAG objBag = NULL;

        RETURN_NTSTATUS_IF_FAILED(AcxObjectBagOpen(&attributes, &objBagCfg, &objBag));
        auto objBag_free = scope_exit([&objBag]() {
            WdfObjectDelete(objBag);
            });

        RETURN_NTSTATUS_IF_FAILED(AcxObjectBagRetrieveSizeT(objBag, &TestName, &sizeValue));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)