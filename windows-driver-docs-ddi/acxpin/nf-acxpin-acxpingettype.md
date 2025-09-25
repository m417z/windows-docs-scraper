## Description

The **AcxPinGetType** function returns the type of the specified pin.

## Parameters

### `AcxPin` [in]

The pin for which to get the type.

## Return value

Returns a value from the [ACX_PIN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_pin_type) enum.

## Remarks

The return value indicates if the pin is a source, a sink, or some other type.

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACX_PIN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/ne-acxpin-acx_pin_type)
- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)