## Description

The DECLARE_CONST_ACXOBJECTBAG_USB_PROPERTY_NAME function declares an ACX object bag property name. USB defined properties start with `usb_`.

## Parameters

### `name`

The name of the declared constant.

## Remarks

### Example

This example shows the definition of DECLARE_CONST_ACXOBJECTBAG_USB_PROPERTY_NAME.

```cpp
	DECLARE_CONST_ACXOBJECTBAG_USB_PROPERTY_NAME(TestUsbName);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)