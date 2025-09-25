## Description

The DECLARE_CONST_ACXOBJECTBAG_SOUNDWIRE_PROPERTY_NAME function declares an ACX object bag property name. Soundwire defined properties start with `sdca_`.

## Parameters

### `name`

The name of the declared ACX object bag property name.

## Remarks

### Example

This example shows the definition of DECLARE_CONST_ACXOBJECTBAG_SOUNDWIRE_PROPERTY_NAME.

```cpp
	DECLARE_CONST_ACXOBJECTBAG_SOUNDWIRE_PROPERTY_NAME(DPNo);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)