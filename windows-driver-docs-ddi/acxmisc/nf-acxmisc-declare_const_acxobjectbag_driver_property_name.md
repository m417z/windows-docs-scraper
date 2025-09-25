## Description

The DECLARE_CONST_ACXOBJECTBAG_DRIVER_PROPERTY_NAME function declares an ACX object bag property name. Driver defined properties start with `drv__`.

## Parameters

### `ven`

The vendor ID that identifies the vendor.

### `name`

The name of the declared ACX object bag property name.

## Remarks

### Example

This example shows the use of DECLARE_CONST_ACXOBJECTBAG_DRIVER_PROPERTY_NAME.

```cpp
    DECLARE_CONST_ACXOBJECTBAG_DRIVER_PROPERTY_NAME(VendorX, TestUI4);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)