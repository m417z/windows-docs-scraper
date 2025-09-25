## Description

The DECLARE_CONST_ACXOBJECTBAG_SYSTEM_PROPERTY_NAME function declares an ACX object bag property name. System defined properties start with `sys_`.

## Parameters

### `name`

The name of the declared constant.

## Remarks

### Example

This example shows the definition of DECLARE_CONST_ACXOBJECTBAG_SYSTEM_PROPERTY_NAME.

```cpp
	DECLARE_CONST_ACXOBJECTBAG_SYSTEM_PROPERTY_NAME(TestSysName);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)