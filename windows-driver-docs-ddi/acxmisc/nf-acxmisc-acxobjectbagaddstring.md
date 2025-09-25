## Description

The AcxObjectBagAddString function adds a WDFSTRING object to an existing, initialized AcxObjectBag. For more information about WDFSTRING, see [wdfstring.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfstring/).

## Parameters

### `ObjectBag`

An initialized ObjectBag ACX object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `ValueName`

A ValueName that will be associated with the added string and can be used to retrieve the stored string.

### `Value`

The value of the WDFSTRING object to be stored in the ObjectBag.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxmisc.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxmisc/)