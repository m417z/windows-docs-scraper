## Description

The **ACX_OBJECTBAG_CONFIG_FLAGS** enumeration defines the configuration for an AcxObjectBag.

## Constants

### `AcxObjectBagConfigNoFlags`

Indicates that no config flags are set.

### `AcxObjectBagConfigEnableReads`

Indicates that reads are enabled.

### `AcxObjectBagConfigEnableWrites`

Indicates that writes are enabled.

### `AcxObjectBagConfigFailIfExist`

Indicates that if an ACXOBJECTBAG with the same identity is already present, creation should fail instead of opening the existing one.

### `AcxObjectBagConfigOpenWithHandle`

Indicates to open the ACXOBJECTBAG whose handle is specified in the configuration structure.

### `AcxObjectBagConfigValidFlags`

For internal validation, do not use.

## Remarks

### Example

This example shows the use of ACX_OBJECTBAG_CONFIG_FLAGS.

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
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)